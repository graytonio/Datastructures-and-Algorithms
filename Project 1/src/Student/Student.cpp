#include "Student.h"
using namespace std;

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
  Student::uid = uid
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
