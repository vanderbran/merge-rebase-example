#include "db.hpp"

int createDB(sqlite3* db) { 

    char* errMSG = nullptr; 
    const char* sql = "CREATE TABLE IF NOT EXISTS Students ("
                       "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "Name TEXT NOT NULL, "
                       "Grade Integer);"; 

    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMSG); 

    if (rc != SQLITE_OK) { 
        std::cerr << "SQL error: " << errMSG << std::endl; 
        sqlite3_free(errMSG); 
        return 1; 
    } else { 
        std::cout << "Table created successfully!" << std::endl;
    }

    return 0;
}

int addExampleStudents(sqlite3* db) { 
    char* errMSG = nullptr; 
    const char* sql1 = "INSERT INTO Students (Name, Grade) VALUES ('Alice', 95); ";
    const char* sql2 = "INSERT INTO Students (Name, Grade) VALUES ('Bob', 87);";

    int rc = sqlite3_exec(db, sql1, nullptr, nullptr, &errMSG); 

    if (rc != SQLITE_OK) { 
        std::cerr << "SQL error: " << errMSG << std::endl; 
        sqlite3_free(errMSG); 
        return 1; 
    } else { 
        std::cout << "Alice added successfully!" << std::endl;
    }

    rc = sqlite3_exec(db, sql2, nullptr, nullptr, &errMSG); 

    if (rc != SQLITE_OK) { 
        std::cerr << "SQL error: " << errMSG << std::endl; 
        sqlite3_free(errMSG); 
        return 1; 
    } else { 
        std::cout << "Bob added successfully!" << std::endl;
    }
    return 0;
}

static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int printStudents(sqlite3* db) { 
    char* errMSG = nullptr; 
    const char* data = "Callback function";
    const char* sql = "SELECT * FROM Students";

    int rc = sqlite3_exec(db, sql, callback, (void*)data, &errMSG); 

    if (rc != SQLITE_OK) { 
        std::cerr << "SQL error: " << errMSG << std::endl; 
        sqlite3_free(errMSG); 
        return 1; 
    } 

    return 0;
}

int dropTable(sqlite3* db) { 
    char* errMSG = nullptr; 
    const char* sql = "DROP TABLE Students;"; 

    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMSG); 

    if (rc != SQLITE_OK) { 
        std::cerr << "SQL Error: " << errMSG << std::endl; 
        sqlite3_free(errMSG); 
        return 1; 
    }

    std::cout << "Table Dropped! " << std::endl; 
    return 0;
}