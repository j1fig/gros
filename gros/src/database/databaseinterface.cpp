#include "databaseinterface.h"
#include "database.h"
#include "sqlcommands.h"
#include "databasedefs.h"

#include <boost/lexical_cast.hpp>
#include <boost/make_shared.hpp>
#include <ctime>
#include <iostream>


DatabaseInterface::DatabaseInterface ()
  : database (boost::make_shared<DataBase>()),
    shouldScheduleRetry (false),
    retries (0)
{
}

DatabaseInterface::DatabaseInterface (std::string databaseName)
  : database (boost::make_shared<DataBase> (databaseName.c_str())),
    shouldScheduleRetry (false),
    retries (0)
{
}

DatabaseInterface::~DatabaseInterface()
{
}


void DatabaseInterface::initTable (const char* tableName)
{
  std::string tableTypesForCommand;
  std::string createTableCommand;
  
  tableTypesForCommand = generateTableTypeString();
  
  createTableCommand = std::string (CREATE_TABLE_COMMAND) +
                       std::string (" ") +
                       std::string (tableName) +
                       std::string (" ") +
                       tableTypesForCommand;
                       
  executeCommand (createTableCommand);
}



std::string DatabaseInterface::generateTableTypeString()
{
  std::string tableTypesForCommand;
  
  // TODO Check for tableTypes size==0 to inhibit this
  tableTypesForCommand.append ("(");
  for (unsigned short tableTypeIndex = 0; tableTypeIndex < tableTypes.size(); tableTypeIndex++) {
    bool isLastIndex = (tableTypeIndex == tableTypes.size() - 1);
    
    tableTypesForCommand.append (tableTypes[tableTypeIndex].first);
    //tableTypesForCommand.append(" ");
    //tableTypesForCommand.append(tableTypes[tableTypeIndex].second);
    
    if (!isLastIndex) {
      tableTypesForCommand.append (",");
      tableTypesForCommand.append (" ");
    }
  }
  tableTypesForCommand.append (")");
  
  return tableTypesForCommand;
}

void DatabaseInterface::executeCommand (std::string theCommand)
{
  database->clearCommand();
  //std::cout << " DatabaseInterface::executeCommand: Executing SQL Command: " << theCommand.c_str() << std::endl;
  database->setCommand (theCommand.c_str());
  database->executeCommand();
}


