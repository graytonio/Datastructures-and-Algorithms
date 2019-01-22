#include "Course.h"
using namespace std;

const string &Course::getCode(){
        return code;
}

void Course::setCode(const string &code){
        Course::code = code;
}

const string &Course::getTitle(){
        return title;
}

void Course::setTitle(const string& title){
        Course::title = title;
}

double Course::getGrade(){
        return grade;
}

void Course::setGrade(double grade){
        Course::grade = grade;
}

uint8_t Course::getCreditHour(){
        return creditHour;
}

void Course::setCreditHour(uint8_t creditHour){
        Course::creditHour = creditHour;
}

Course::Course(){
}

Course::Course(string codePar, string titlePar, double gradePar, uint8_t creditPar){
        code = codePar;
        title = titlePar;
        grade = gradePar;
        creditHour = creditPar;
}

ostream& operator << (ostream& os, const Course &c){
        os << "Code: " << c.code << "\nTitle: " << c.title << "\nGrade: " << c.grade << "\nCredit Hours: " << unsigned(c.creditHour) << endl;
}
