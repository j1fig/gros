#ifndef DATABASEDEFS_H
#define DATABASEDEFS_H



#define NODE_TABLE_NAME "stats_node"
#define NODE_COLUMNS 6
#define NODE_NODE_ID_COLUMN_NAME "unique_id"



#define STATE_TABLE_NAME "stats_state"



#define CONFIG_TABLE_NAME "stats_configuration"
#define CONFIG_COLUMNS 4
#define CONFIG_COMMAND_COLUMN_NAME "command"
#define CONFIG_COMMAND_STATUS_COLUMN_NAME "status"
#define CONFIG_COMMAND_STATUS_COLUMN_NAME_Q "'status'"

#endif // DATABASEDEFS_H
