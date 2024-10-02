#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
public:
    // Constructor and Destructor
    Database(const std::string& dbPath);
    ~Database();

    // Execute an SQL statement
    bool executeSQL(const std::string& sql, char** errorMessage);

    // Create basic tables if not already created
    void createTables();

private:
    sqlite3* db;
};

#endif // DATABASE_H
