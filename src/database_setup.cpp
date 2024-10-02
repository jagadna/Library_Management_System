#include <iostream>
#include <sqlite3.h>

int main() {
    std::cout << "Starting the program..." << std::endl;

    sqlite3 *db;
    int exit_code = sqlite3_open("data/library.db", &db);

    std::cout << "sqlite3_open called with return code: " << exit_code << std::endl;

    if (exit_code != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    } else {
        std::cout << "Opened/Created database successfully!" << std::endl;
    }

    sqlite3_close(db);
    std::cout << "Database connection closed successfully." << std::endl;

    return 0;
}
