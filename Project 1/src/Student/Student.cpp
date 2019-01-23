#include "Student.h"
using namespace std;

Student::Student() : Person(){
}

Student::Student(uint32_t uidPar, double gpaPar, vector<Course> coursesPar, string namePar, uint32_t agePar) : Person(namePar, agePar){
        uid = uidPar;
        gpa = gpaPar;
        courses = coursesPar;
        calculateCourses();
}

uint32_t Student::getTotalCreditHours(){
        return totalCreditHours;
}

void Student::setTotalCreditHours(uint32_t totalCreditHours){
        Student::totalCreditHours = totalCreditHours;
}

uint32_t Student::getNumberOfCourses(){
        return numberOfCourses;
}

void Student::setNumberOfCourses(uint32_t numberOfCourses){
        Student::numberOfCourses = numberOfCourses;
}

uint32_t Student::getUID(){
        return uid;
}

void Student::setUID(uint32_t uid){
        Student::uid = uid;
}

double Student::getGPA(){
        return gpa;
}

void Student::setGPA(double gpa){
        Student::gpa = gpa;
}

vector<Course> Student::getCourses(){
        return courses;
}

void Student::setCourses(vector<Course> courses){
        Student::courses = courses;
}

void Student::addCourse(Course newCourse){
        courses.push_back(newCourse);
        calculateCourses();
}

void Student::deleteCourse(uint8_t index){
        courses.erase(courses.begin() + index);
        calculateCourses();
}

void Student::calculateCourses(){
        numberOfCourses = courses.size();
        uint32_t credits = 0;
        for(Course c : courses) {
                credits += c.getCreditHour();
        }
        totalCreditHours = credits;
}

ostream& operator << (ostream& os, Student &s){
        os << "Name: " << s.getName() << "\nAge: " << unsigned(s.getAge()) << "\nCredit Hours: " << s.totalCreditHours << "\nNumber of Courses: " << s.numberOfCourses << "\nStudent ID: " << s.uid << "\nGPA: " << s.gpa << endl;
}
