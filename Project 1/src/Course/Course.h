#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <cstdint>
#include <string>

class Course {
private:
std::string code;
std::string title;
double grade;
uint8_t creditHour;

public:
//Constructors
Course();
Course(std::string codePar, std::string titlePar, double gradePar, uint8_t creditPar);

//Course Code Getter and Setter
const std::string &getCode();
void setCode(const std::string &code);

//Course Title Getter and Setter
const std::string &getTitle();
void setTitle(const std::string &title);

//Student Grade Getter and Setter
double getGrade();
void setGrade(double grade);

//Course Credit Hours Getter and Setter
uint8_t getCreditHour();
void setCreditHour(uint8_t creditHour);

//Cout Operator Definition
friend std ::ostream& operator<<(std::ostream &os, const Course &c);
};

#endif
