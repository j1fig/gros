#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <boost/smart_ptr.hpp>
#include <vector>


class DataBase;

class DatabaseInterface
{
  public:
    typedef std::pair<std::string, std::string> TableType;
    
    DatabaseInterface ();
    DatabaseInterface (std::string databaseName);
    
    virtual ~DatabaseInterface();

    
    void initTable (const char* tableName);
    std::string generateTableTypeString ();
    
    
    void executeCommand (std::string theCommand);
    
    
  private:
    boost::shared_ptr<DataBase> database;
    
    std::vector<TableType> tableTypes;
    
    bool shouldScheduleRetry;
    unsigned int retries;
    
    static const unsigned MAX_RETRIES = 100;
    static const unsigned DB_RETRY_PERIOD_MS = 1000;
    static const unsigned TIMER_PERIOD_MS = 5000;
};

#endif // DATABASEINTERFACE_H
