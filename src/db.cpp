#include "db.hpp"

int createDB(sqlite3* db) { 

    char* errMSG = nullptr; 
    const char* stmt = "CREATE TABLE IF NOT EXISTS Students ("
                       "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "Name TEXT NOT NULL, "
                       "Grade Integer);"; 

    int rc = sqlite3_exec(db, stmt, nullptr, nullptr, &errMSG); 

    if (rc != SQLITE_OK) { 
        std::cerr << "SQL error: " << errMSG << std::endl; 
        sqlite3_free(errMSG); 
        return 1; 
    } else { 
        std::cout << "Table created successfully!" << std::endl;
    }

    sqlite3_close(db);
    return 0;
}