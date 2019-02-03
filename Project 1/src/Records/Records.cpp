#include "Records.h"
using namespace std;

//Default Constructor
Records::Records(){
}

//Base Constructor
Records::Records(vector<Student> studentsPar){
        students = studentsPar;
        processStudents(); //Calculate GPA, Number of Students, and Total Credit Hours
}

//Total Number of Students Getter
uint32_t Records::getNumberOfStudents(){
        return numberOfStudents;
}

//Total Number of Students Setter
void Records::setNumberOfStudents(uint32_t numberOfStudents){
        Records::numberOfStudents = numberOfStudents;
}

//Average GPA Getter
double Records::getAverageGPA(){
        return averageGPA;
}

//Average GPA Setter
void Records::setAverageGPA(double averageGPA){
        Records::averageGPA = averageGPA;
}

//Student Vector Getter
vector<Student> Records::getStudents(){
        return Records::students;
}

//Student Vector Setter
void Records::setStudents(vector<Student> *students){
        Records::students = *students;
}

//Find Student by UID and return pointer to Student Object
Student* Records::getStudent(uint32_t uid){
        for(uint32_t i = 0; i < students.size(); i++) {
                if(students.at(i).getUID() == uid) return &students.at(i);
        }
        return NULL;
}

//Add Student Object to Student Vector
bool Records::addStudent(Student *student){
        for(uint32_t i = 0; i < students.size(); i++) { //Loop through students and check for an identical UID
                if(students.at(i).getUID() == student->getUID()) return false;
        }

        students.push_back(*student); //If no duplicate push new student
        return true;
}

//Find Student by UID and remove it from the vector
Student Records::deleteStudent(uint32_t uid){
        Student s;
        for(uint32_t i = 0; i<students.size(); i++) {
                if(students.at(i).getUID() == uid) {
                        s = students.at(i);
                        students.erase(students.begin() + i);
                        return s;
                }
        }
        return s;
}

//cout operator definition
ostream& operator << (ostream& os, const Records &r){
        os << "Number Of Students: " << r.numberOfStudents << "\nAverage GPA: " << r.averageGPA << "\nStudents: \n";
        for(Student s : r.students) {
                os << "\n" << s;
        }
        os << endl;
}

//Perform processing on the student vector
void Records::processStudents(){
        double totalGPA = 0; //Sum of all GPAs
        for(Student s : students) { //For each student in the students vector
                totalGPA += s.getGPA(); //Add the GPA to the total
        }
        numberOfStudents = students.size(); //Set the Number of Students to the size of the student vector
        averageGPA = totalGPA / numberOfStudents; //Calculate the average gpa
}
