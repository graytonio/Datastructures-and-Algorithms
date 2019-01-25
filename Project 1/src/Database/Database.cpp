#include "Database.h"
using namespace std;

Database::Database(){
}

Database::Database(string pathStudentsPar, string pathCoursesPar){
        pathStudents = pathStudentsPar;
        pathCourses = pathCoursesPar;
        records = loadData();
}

string Database::getPathStudents(){
        return pathStudents;
}

void Database::setPathStudents(string path){
        Database::pathStudents = path;
}

string Database::getPathCourses(){
        return pathCourses;
}

void Database::setPathCourses(string path){
        Database::pathCourses = path;
}

Records* Database::getRecords(){
        return &records;
}

void Database::setRecords(Records records){
        Database::records = records;
}

Records Database::loadData(){
        vector<Student> students;
        vector<Course> courses;
        ifstream inputFile(pathStudents);
        Student tempStudent;
        string cell; //Temporary holding variable for each value in the csv record
        while(getline(inputFile, cell, ',')) {
                tempStudent.setUID((uint32_t) stoi(cell));

                getline(inputFile, cell, ',');
                tempStudent.setName(cell);

                getline(inputFile, cell, ',');
                tempStudent.setAge((uint32_t) stoi(cell));

                getline(inputFile, cell, ',');
                tempStudent.setTotalCreditHours((uint32_t) stoi(cell));

                getline(inputFile, cell, ',');
                tempStudent.setNumberOfCourses((uint32_t) stoi(cell));

                getline(inputFile, cell);
                tempStudent.setGPA((double) stod(cell));

                students.push_back(tempStudent);
        }

        ifstream inputCourse(pathCourses);
        Course tempCourse;
        Student *currentStudent = NULL;
        while(getline(inputCourse, cell, ',')) {
                for(vector<Student>::iterator i = students.begin(); i != students.end(); i++) {
                        Student s = (*i);
                        if(s.getUID() == (uint32_t) stoi(cell)) {
                                currentStudent = &(*i);
                                break;
                        }
                }

                getline(inputCourse, cell, ',');
                tempCourse.setCode(cell);

                getline(inputCourse, cell, ',');
                tempCourse.setTitle(cell);

                getline(inputCourse, cell, ',');
                tempCourse.setCreditHour((uint8_t) stoi(cell));

                getline(inputCourse, cell);
                tempCourse.setGrade(stod(cell));

                currentStudent->addCourse(tempCourse);
        }

        Records r(students);
        return r;
}

//TODO: Create Save Data Function Implementation
