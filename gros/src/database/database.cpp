#include "database.h"

#include <iostream>

DataBase::DataBase()
{
    initialize();
}

DataBase::DataBase(const char* dbFileName)
{
    initialize();
    setFileName(dbFileName);
    open();
}

DataBase::~DataBase()
{
    close();
}

void DataBase::setCommand     (const char* command)
{
    int sqlError = SQLITE_OK;
    const char* unusedCommandString;

    sqlError = sqlite3_prepare_v2(handle, command, COMMAND_MAX_SIZE, &statement, &unusedCommandString);
    setUnusedCommand(unusedCommandString);

    if (sqlError!=SQLITE_OK)
    {
        std::cout << " DataBase::setCommand: throwing " << sqlError << std::endl;
        throw sqlError;
    }

    isStatementPrepared = true;
    isCommandFinished = false;
}

void DataBase::setCommand     (const char* command, int commandSize)
{
    int sqlError = SQLITE_OK;
    const char* unusedCommandString;

    sqlError = sqlite3_prepare_v2(handle, command, commandSize, &statement, &unusedCommandString);
    setUnusedCommand(unusedCommandString);

    if (sqlError!=SQLITE_OK)
        throw sqlError;

    isStatementPrepared = true;
    isCommandFinished = false;
}

void DataBase::clearCommand   (void)
{
    int sqlError = SQLITE_OK;

    sqlError = sqlite3_finalize(statement);

    if (sqlError!=SQLITE_OK)
        throw sqlError;

    isStatementPrepared = false;
}

void DataBase::stepLine       (void)
{
    int sqlError = SQLITE_ROW;

    if (shouldResetStatement)
        resetStatement();

    sqlError = sqlite3_step(statement);

    if (sqlError!=SQLITE_ROW)
    {
        if (sqlError==SQLITE_DONE)
        {
            isCommandFinished = true;
            shouldResetStatement = true;
        }
        else
            throw sqlError;
    }
}

void DataBase::stepColumn     (void)
{
    int sqlError = SQLITE_OK;
}

void DataBase::setUnusedCommand   (const char* unusedCommandString)
{
    unusedCommand.clear();
    unusedCommand.append(unusedCommandString);
}

void DataBase::initialize (void)
{
    handle = 0;
    isCommandFinished = true;
    rowAvailable = false;
    shouldResetStatement = false;
    isStatementPrepared = false;
}

void DataBase::open (void)
{
    int sqlError = SQLITE_OK;

    sqlError = sqlite3_open(fileName.c_str(),&handle);
    if (sqlError!=SQLITE_OK)
        throw sqlError;
}

void DataBase::close (void)
{
    int sqlError = SQLITE_OK;

    if (isStatementPrepared)
        clearCommand();

    sqlError = sqlite3_close(handle);
    if (sqlError!=SQLITE_OK)
        throw sqlError;
}

void DataBase::setFileName    (const char* fileName)
{
    std::string tmpFileName(fileName);
    this->fileName = tmpFileName;
}

void DataBase::resetStatement (void)
{
    int sqlError = SQLITE_OK;

    sqlError = sqlite3_reset(statement);
    if (sqlError!=SQLITE_OK)
        throw sqlError;
}



