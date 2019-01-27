#include "Course.h"
using namespace std;


//Default Constructor
Course::Course(){
}

//Constructor
Course::Course(string codePar, string titlePar, double gradePar, uint8_t creditPar){
        code = codePar;
        title = titlePar;
        grade = gradePar;
        creditHour = creditPar;
}

//Course Code Getter
const string &Course::getCode(){
        return code;
}

//Course Code Setter
void Course::setCode(const string &code){
        Course::code = code;
}

//Course Title Getter
const string &Course::getTitle(){
        return title;
}

//Course Title Setter
void Course::setTitle(const string& title){
        Course::title = title;
}

//Course Grade Getter
double Course::getGrade(){
        return grade;
}

//Course Grade Setter
void Course::setGrade(double grade){
        Course::grade = grade;
}

//Course Credit Hour Getter
uint8_t Course::getCreditHour(){
        return creditHour;
}

//Course Credit Hour Setter
void Course::setCreditHour(uint8_t creditHour){
        Course::creditHour = creditHour;
}

ostream& operator << (ostream& os, const Course &c){
        os << "\tCode: " << c.code << "\n\tTitle: " << c.title << "\n\tGrade: " << c.grade << "\n\tCredit Hours: " << unsigned(c.creditHour) << endl;
}
