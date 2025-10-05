/* 
Author: Brandon Vandergriff
Date: 10/5/2025
Purpose: Creating a C++ project for students to practice merge / rebase on git.  
*/

#include "db.hpp"

int main() { 
    sqlite3* db; 

    int rc = sqlite3_open("example.db", &db); 

    if (rc) { 
        std::cerr << "Error opening DB: " << sqlite3_errmsg(db) << std::endl; 
        sqlite3_close(db); 
        return 1; 
    }

    std::cout << "Opened database successfully!" << std::endl; 
    sqlite3_close(db);

    // guys DB stands for "da best" and i think horses are cool
    // - average developer logic 
    horse(); 

    return 0; 
}