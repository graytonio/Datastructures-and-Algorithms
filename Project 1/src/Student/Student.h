#ifndef STUDENT_H
#define STUDENT_H

#include "../Person/Person.h"
#include "../Course/Course.h"
#include <vector>
#include <iostream>
#include <cstdint>
#include <string>

class Student : public Person {
private:
uint32_t totalCreditHours;
uint32_t numberOfCourses;
uint32_t uid;
double gpa;
std::vector<Course> courses;
void calculateCourses();

public:
//Constructor
Student();
Student(uint32_t uidPar, double gpaPar, std::vector<Course> coursesPar, std::string namePar, uint32_t agePar);

//Total Credit Hours Getter and Setter
uint32_t getTotalCreditHours();
void setTotalCreditHours(uint32_t totalCreditHours);

//Number of Courses Getter and Setter
uint32_t getNumberOfCourses();
void setNumberOfCourses(uint32_t numberOfCourses);

//UID Getter and Setter
uint32_t getUID();
void setUID(uint32_t uid);

//GPA Getter and Setter
double getGPA();
void setGPA(double gpa);

//Courses Vector Getter and Setter
std::vector<Course> getCourses();
void setCourses(std::vector<Course> courses);

//Add Course to courses vector
void addCourse(Course newCourse);

//Delete Course by Course Code
bool deleteCourse(std::string code);

//cout operator definition
friend std ::ostream& operator<<(std::ostream &os, Student &s);
};

#endif
