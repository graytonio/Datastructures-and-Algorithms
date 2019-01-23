#include "Records.h"
#include <iostream>
using namespace std;

Records::Records(){
}

Records::Records(vector<Student> studentsPar){
        students = studentsPar;
        processStudents();
}

uint32_t Records::getNumberOfStudents(){
        return numberOfStudents;
}

void Records::setNumberOfStudents(uint32_t numberOfStudents){
        Records::numberOfStudents = numberOfStudents;
}

double Records::getAverageGPA(){
        return averageGPA;
}

void Records::setAverageGPA(double averageGPA){
        Records::averageGPA = averageGPA;
}

vector<Student> Records::getStudents(){
        return Records::students;
}

void Records::setStudents(vector<Student> students){
        Records::students = students;
}

ostream& operator << (ostream& os, const Records &r){
        os << "Number Of Students: " << r.numberOfStudents << "\nAverage GPA: " << r.averageGPA << "\nStudents: ";
        for(Student s : r.students) {
                os << "\n" << s;
        }
        os << endl;
}

void Records::processStudents(){
        double totalGPA = 0;
        for(Student s : students) {
                totalGPA += s.getGPA();
        }
        numberOfStudents = students.size();
        averageGPA = totalGPA / numberOfStudents;
}
