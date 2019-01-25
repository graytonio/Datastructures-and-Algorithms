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
Records();
Records(std::vector<Student> studentsPar);

uint32_t getNumberOfStudents();
void setNumberOfStudents(uint32_t numberOfStudents);

double getAverageGPA();
void setAverageGPA(double averageGPA);

std::vector<Student> getStudents();
void setStudents(std::vector<Student> students);

Student* getStudent(uint32_t uid);
void addStudent(Student student);

friend std ::ostream& operator<<(std::ostream &os, const Records &r);
};

#endif
