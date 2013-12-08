#include "database.h"

#include <iostream>
#include <cstring>



const char* DataBase::DEFAULT_DB = "db";



DataBase::DataBase() : handle (0),
  isCommandFinished (true),
  rowAvailable (false),
  shouldResetStatement (false),
  isStatementPrepared (false),
  rowIndex (0)
{
  setFileName (DEFAULT_DB);
  sqlite3_busy_timeout (handle, DB_BUSY_RETRY_PERIOD_MS);
}



DataBase::DataBase (const char* dbFileName) : handle (0),
  isCommandFinished (true),
  rowAvailable (false),
  shouldResetStatement (false),
  isStatementPrepared (false),
  rowIndex (0)
{
  setFileName (dbFileName);
  open();
  
  sqlite3_busy_timeout (handle, DB_BUSY_RETRY_PERIOD_MS);
}



DataBase::~DataBase()
{
  close();
}



void DataBase::setCommand (const char* command)
{
  setCommand (command, COMMAND_MAX_SIZE);
}



void DataBase::setCommand (const char* command, int commandSize)
{
  int sqlError = SQLITE_OK;
  const char* unusedCommandString;
  
  sqlError = sqlite3_prepare_v2 (handle, command, commandSize, &statement, &unusedCommandString);
  setUnusedCommand (unusedCommandString);
  
  isCommandFinished = false;
  shouldResetStatement = false;
  rowIndex = 0;
  result.clear();
  
  if (sqlError != SQLITE_OK) {
    throw sqlError;
  }
  
  isStatementPrepared = true;
}



void DataBase::clearCommand (void)
{
  int sqlError = SQLITE_OK;
  
  sqlError = sqlite3_finalize (statement);
  
  isStatementPrepared = false;
  
  if (sqlError != SQLITE_OK) {
    throw sqlError;
  }
}



void DataBase::executeCommand (void)
{
  int commandStatus = SQLITE_DONE;
  
  do {
    commandStatus = stepLine();
  }
  while (commandStatus == SQLITE_ROW);
}



DataBase::Result DataBase::getCommandResult() const
{
  return result;
}



int DataBase::stepLine (void)
{
  int stepStatus = SQLITE_DONE;
  
  if (shouldResetStatement) {
    resetStatement();
  }
  
  stepStatus = sqlite3_step (statement);
  
  switch (stepStatus) {
    case SQLITE_ROW: {
      stepColumn();
      break;
    }
    case SQLITE_DONE: {
      isCommandFinished = true;
      shouldResetStatement = true;
      break;
    }
    default:
      throw stepStatus;
      break;
  }
  
  return stepStatus;
}



void DataBase::stepColumn (void)
{
  int numCols =  sqlite3_column_count (statement);
  
  allocateResultLines();
  allocateResultColumns (numCols);
  
  for (int colIndex = 0; colIndex < numCols; colIndex++) {
    readColumn (colIndex);
  }
  
  rowIndex++;
}



void DataBase::setUnusedCommand (const char* unusedCommandString)
{
  unusedCommand.clear();
  unusedCommand.append (unusedCommandString);
}



void DataBase::open (void)
{
  int sqlError = SQLITE_OK;
  
  sqlError = sqlite3_open (fileName.c_str(), &handle);
  if (sqlError != SQLITE_OK) {
    throw sqlError;
  }
}



void DataBase::close (void)
{
  int sqlError = SQLITE_OK;
  
  if (isStatementPrepared) {
    clearCommand();
  }
  
  sqlError = sqlite3_close (handle);
  if (sqlError != SQLITE_OK) {
    throw sqlError;
  }
}



void DataBase::setFileName (const char* fileName)
{
  std::string tmpFileName (fileName);
  this->fileName = tmpFileName;
}



void DataBase::resetStatement (void)
{
  int sqlError = SQLITE_OK;
  
  sqlError = sqlite3_reset (statement);
  
  shouldResetStatement = false;
  
  if (sqlError != SQLITE_OK) {
    throw sqlError;
  }
}



void DataBase::allocateResultLines()
{
  if ( (rowIndex + 1) > result.size()) {
    result.resize (rowIndex + 1);
  }
}



void DataBase::allocateResultColumns (int columns)
{
  result[rowIndex].resize (columns);
}



void DataBase::readColumn (int columnIndex)
{
  /// TO DO TEST/REFACTOR - possibly some dangerous pointer manipulation being done
  char currentString[COLUMN_VALUE_MAX_SIZE];
  
  const unsigned char* colString = sqlite3_column_text (statement, columnIndex);
  int colSize = sqlite3_column_bytes (statement, columnIndex);
  
  if (colSize) {
    memcpy (&currentString[0], colString, colSize);
    currentString[colSize] = '\0';
    std::string columnStringForResult (currentString);
    result[rowIndex][columnIndex] = columnStringForResult;
  }
}
