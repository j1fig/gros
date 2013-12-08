#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <sqlite3.h>



class DataBase
{
  public:
    typedef std::vector< std::vector< std::string > > Result;
    
    DataBase();
    DataBase (const char* dbFileName);
    virtual ~DataBase();
    
    void setCommand (const char* command);
    void setCommand (const char* command, int commandSize);
    void clearCommand (void);
    
    void executeCommand (void);
    
    Result getCommandResult (void) const;
    
  private:
    void setFileName (const char* fileName);
    
    void open (void);
    void close (void);
    
    void setUnusedCommand (const char* unusedCommandString);
    
    void resetStatement (void);
    
    
    void allocateResultLines ();
    void allocateResultColumns (int columns);
    
    void readColumn (int columnIndex);
    
    int stepLine (void);
    void stepColumn (void);
    
  private:
    sqlite3* handle;
    std::string fileName;
    
    sqlite3_stmt* statement;
    std::string unusedCommand;
    
    Result result;
    
    unsigned int rowIndex;
    
    bool rowAvailable;
    bool isCommandFinished;
    bool shouldResetStatement;
    bool isStatementPrepared;
    
    static const unsigned COMMAND_MAX_SIZE = 256;
    static const unsigned COMMAND_UNUSED_MAX_SIZE = 256;
    static const unsigned COLUMN_VALUE_MAX_SIZE = 64;
    
    static const unsigned DB_BUSY_RETRY_PERIOD_MS = 1000;
    static const char* DEFAULT_DB;
};

#endif // DATABASE_H
