#include "Records.h"
#include "../Course/Course.h"
#include <iostream>
using namespace std;

int main(){
        //Initialize a vector for courses and students
        vector<Course> courses;
        vector<Student> students;

        courses.push_back(Course("COP3530", "Datastructures and Algorithms", 93.3, 3)); //Push a course to the courses vector
        students.push_back(Student(5252, 3.42, courses, "Grayton Ward", 19)); //Push a student to the vector

        Records r(students); //Create a Records Object
        cout << r;

        courses.push_back(Course("MAP2302", "Differential Equations", 83.2, 3)); //Add a course to the courses vector
        r.addStudent(Student(5253, 3.29, courses, "Wrayton Gard", 20)); //Add a new student with the new courses vector
        cout << r;

        r.deleteStudent(5252); //Remove a student from the vector
        cout << r;

        return 0;
}
