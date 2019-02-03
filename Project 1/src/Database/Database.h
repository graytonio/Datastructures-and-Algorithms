#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <algorithm>
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
//Constructors
Database();
Database(std::string pathStudentsPar, std::string pathCoursesPar);

//Student Path Getter and Setter
std::string getPathStudents();
void setPathStudents(std::string path);

//Course Path Getter and Setter
std::string getPathCourses();
void setPathCourses(std::string path);

//Records Object Getter and Setter
Records* getRecords();
void setRecords(Records records);

//Load the data from the files specified by the Student and Course Paths
Records* loadData();

//Save the current Record Data into the files specified by the Student and Course Paths
void saveData();

//Cout Operator Definition
friend std ::ostream& operator<<(std::ostream &os, Student &s);
};

#endif
