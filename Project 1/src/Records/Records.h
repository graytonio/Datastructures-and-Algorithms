#ifndef RECORDS_H
#define RECORDS_H

#include "../Student/Student.h"
#include <vector>

class Records {
private:
uint32_t numberOfStudents;
double averageGPA;
std::vector<Student> students;
void processStudents();

public:
//Constructors
Records();
Records(std::vector<Student> studentsPar);

//Number of Students Getter and Setter
uint32_t getNumberOfStudents();
void setNumberOfStudents(uint32_t numberOfStudents);

//Average GPA Getter and Setter
double getAverageGPA();
void setAverageGPA(double averageGPA);

//Student Vector Getter and Setter
std::vector<Student> getStudents();
void setStudents(std::vector<Student> *students);

//Get Student Pointer by UID
Student* getStudent(uint32_t uid);

//Add student to students vector
bool addStudent(Student *student);

//Remove Student by UID
Student deleteStudent(uint32_t uid);

//cout operator definition
friend std ::ostream& operator<<(std::ostream &os, const Records &r);
};

#endif
