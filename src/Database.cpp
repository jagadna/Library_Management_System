#include "Database.h"
#include <iostream>  // For error messages
#include <sqlite3.h> // For SQLite functions like sqlite3_exec, sqlite3_open, sqlite3_close

// Constructor
Database::Database(const std::string& dbPath) {
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Destructor
Database::~Database() {
    if (db) {
        sqlite3_close(db);
    }
}

// Execute SQL command
bool Database::executeSQL(const std::string& sql, char** errorMessage) {
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, errorMessage);
    if (rc != SQLITE_OK) {
        return false;
    }
    return true;
}

// Create basic tables if not already created
void Database::createTables() {
    std::string booksTable = "CREATE TABLE IF NOT EXISTS books ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "title TEXT NOT NULL, "
                             "author TEXT NOT NULL, "
                             "isbn TEXT UNIQUE NOT NULL, "
                             "year INTEGER NOT NULL, "
                             "available INTEGER DEFAULT 1);";
    std::string usersTable = "CREATE TABLE IF NOT EXISTS users ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "name TEXT NOT NULL, "
                             "email TEXT UNIQUE NOT NULL);";

    char* errorMessage = nullptr;
    if (!executeSQL(booksTable, &errorMessage)) {
        std::cerr << "Error creating books table: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
    if (!executeSQL(usersTable, &errorMessage)) {
        std::cerr << "Error creating users table: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
}
