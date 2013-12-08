#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>


#define COMMAND_MAX_SIZE 256
#define COMMAND_UNUSED_MAX_SIZE COMMAND_MAX_SIZE

class DataBase
{
public:
    DataBase();
    DataBase(const char* dbFileName);
    virtual ~DataBase();

    void setCommand     (const char* command);
    void setCommand     (const char* command, int commandSize);
    void clearCommand   (void);

    void stepLine       (void);
    void stepColumn     (void);

private:
    void initialize     (void);
    void setFileName    (const char* fileName);

    void open           (void);
    void close          (void);

    void setUnusedCommand   (const char* unusedCommandString);

    void resetStatement     (void);

private:
    sqlite3* handle;
    std::string fileName;

    sqlite3_stmt* statement;
    std::string unusedCommand;

    bool rowAvailable;
    bool isCommandFinished;
    bool shouldResetStatement;
    bool isStatementPrepared;
};

#endif // DATABASE_H
