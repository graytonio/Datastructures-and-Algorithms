#ifndef MENU_H
#define MENU_H

#include "../Database/Database.h"
#include <iostream>
#include <ios>
#include <limits>

class Menu {
private:
Database data;
void printRecords();
void printSingleRecord();
void addStudent();
void deleteStudent();
void addCourse();
void deleteCourse();
void clearConsole();

public:
Menu();
Menu(Database dataPar);
bool printMenu();
};

#endif
