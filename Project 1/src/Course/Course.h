#ifndef COURSE_H
#define PERSON_H

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
Course();
Course(std::string codePar, std::string titlePar, double gradePar, uint8_t creditPar);

const std::string &getCode();
void setCode(const std::string &code);

const std::string &getTitle();
void setTitle(const std::string &title);

double getGrade();
void setGrade(double grade);

uint8_t getCreditHour();
void setCreditHour(uint8_t creditHour);

friend std ::ostream& operator<<(std::ostream &os, const Course &c);
};

#endif
