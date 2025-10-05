#pragma once 
#include<iostream> 
#include<sqlite3.h>

int createDB(sqlite3*); 

int addExampleStudents(sqlite3*); 

int printStudents(sqlite3*); 

static int callback(void* data, int argc, char** argv, char** azColName);

int dropTable(sqlite3*); 