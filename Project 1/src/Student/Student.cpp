#include "Student.h"
using namespace std;

//Default Constructor
Student::Student() : Person(){
        gpa = 0;
        totalCreditHours = 0;
        numberOfCourses = 0;
        name = "NA";
}

//Base Constructor
Student::Student(uint32_t uidPar, double gpaPar, vector<Course> coursesPar, string namePar, uint32_t agePar) : Person(namePar, agePar){
        uid = uidPar;
        gpa = gpaPar;
        courses = coursesPar;
        calculateCourses();
}

//Total Credit Hours Getter
uint32_t Student::getTotalCreditHours(){
        return totalCreditHours;
}

//Total Credit Hours Setter
void Student::setTotalCreditHours(uint32_t totalCreditHours){
        Student::totalCreditHours = totalCreditHours;
}

//Number of Courses Getter
uint32_t Student::getNumberOfCourses(){
        return numberOfCourses;
}

//Number of Courses Setter
void Student::setNumberOfCourses(uint32_t numberOfCourses){
        Student::numberOfCourses = numberOfCourses;
}

//UID Getter
uint32_t Student::getUID(){
        return uid;
}

//UID Setter
void Student::setUID(uint32_t uid){
        Student::uid = uid;
}

//GPA Getter
double Student::getGPA(){
        return gpa;
}

//GPA Setter
void Student::setGPA(double gpa){
        Student::gpa = gpa;
}

//Courses Vector Getter
vector<Course> Student::getCourses(){
        return courses;
}

//Courses Vector Setter
void Student::setCourses(vector<Course> courses){
        Student::courses = courses;
        calculateCourses(); //Re-calculate student information based on new courses vector
}

//Add a new course object to the courses vector
void Student::addCourse(Course newCourse){
        courses.push_back(newCourse);
        calculateCourses(); //Re-calculate student information based on new courses vector
}

//Remove a course based on the Course Code
bool Student::deleteCourse(string code){
        for(int i=0; i<courses.size(); i++) { //For each course in courses vector
                if(courses.at(i).getCode() == code) { //If the course code matches the passed course code
                        courses.erase(courses.begin() + i); //Remove the course from the vector
                        calculateCourses(); //Re-calculate student information based on new courses vector
                        return true;
                }
        }
        return false; //The course code was not found
}

//Calculate Total Credit Hours and GPA based on Courses vector
void Student::calculateCourses(){
        gpa = 0; //Set the GPA to 0
        totalCreditHours = 0; //Set Total Credit Hours to 0
        numberOfCourses = courses.size(); //Number of Courses is set to the size of the courses vector

        for(Course c : courses) { //For each course in the vector
                totalCreditHours += c.getCreditHour(); //Add the credit hours to the total
                double grade = c.getGrade(); //Get the grade from the course for comparison
                if(grade>=90 && grade<=100) { //If A
                        gpa+= 4 * c.getCreditHour(); //Weigh the gpa with 4 points
                } else if(grade>=80 && grade<=89) { //If B
                        gpa+= 3 * c.getCreditHour(); //Weight the gpa with 3 points
                } else if(grade>=70 && grade<=79) { //If C
                        gpa+= 2 * c.getCreditHour(); //Weight the gpa with 2 points
                } else if(grade>=60 && grade<=79) { //If D
                        gpa+= 1 * c.getCreditHour(); //Weight the gpa with 1 point
                }

        }
        gpa /= totalCreditHours; //Divide the total GPA by the Total Credit Hours
}

//cour operator definition
ostream& operator << (ostream& os, Student &s){
        os << "Name: " << s.name << "\nAge: " << unsigned(s.age) << "\nCredit Hours: " << s.totalCreditHours << "\nNumber of Courses: " << s.numberOfCourses << "\nStudent ID: " << s.uid << "\nGPA: " << s.gpa << "\nCourses: ";
        for(Course c : s.courses) { //Loop through all the courses and print them
                os << "\n" << c;
        }
        os << endl;
}
