/* 
Author: Brandon Vandergriff
Date: 10/5/2025
Purpose: Creating a C++ project for students to practice merge / rebase on git.  
*/

#include "db.hpp"

int main() { 
    sqlite3* db; 

    // if fails, returns a non-zero number
    int rc = sqlite3_open("example.db", &db); 

    // did it pass? 
    if (rc) { 
        std::cerr << "Error opening DB: " << sqlite3_errmsg(db) << std::endl; 
        sqlite3_close(db); 
        return 1; 
    }

    // awww yiss
    std::cout << "Opened database successfully!" << std::endl; 

    if(createDB(db)) { 
        std::cerr << "CreateDB function failed. " << std::endl; 
        return 1; 
    }
    sqlite3_close(db);

    return 0; 
}