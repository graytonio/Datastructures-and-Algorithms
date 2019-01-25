#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include "../Records/Records.h"
#include "../Student/Student.h"
#include "../Course/Course.h"

class Database {
private:
std::string pathStudents;
std::string pathCourses;
Records records;

public:
Database();
Database(std::string pathStudentsPar, std::string pathCoursesPar);

std::string getPathStudents();
void setPathStudents(std::string path);

std::string getPathCourses();
void setPathCourses(std::string path);

Records getRecords();
void setRecords(Records records);

Records loadData();
void saveData();

friend std ::ostream& operator<<(std::ostream &os, Student &s);
};

#endif
