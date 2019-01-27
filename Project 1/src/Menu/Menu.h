#ifndef MENU_H
#define MENU_H

#include "../Database/Database.h"
#include <iostream>
#include <ios>
#include <limits>

class Menu {
private:
Database data;

//Functions for each menu option
void printRecords();
void printSingleRecord();
void addStudent();
void deleteStudent();
void addCourse();
void deleteCourse();
void clearConsole();
bool isNumber(std::string s);

public:
//Constructors
Menu();
Menu(Database dataPar);

//Print menu and send user to appropriate function
bool printMenu();
};

#endif
