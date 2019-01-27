#include "Student.h"
#include <iostream>
using namespace std;

int main(){
        //Create Courses Vector
        vector<Course> courses;

        courses.push_back(Course("COP3530", "Datastructures and Algorithms", 93.3, 3)); //Push course to courses vector
        Student s(5252, 3.42, courses, "Grayton Ward", 19); //Create Student with courses vector
        cout << s;

        s.addCourse(Course("MAP2302", "Differential Equations", 87.2, 3)); //Add a course to the Student
        cout << s;

        s.deleteCourse("COP3530"); //Remove Course COP3530
        cout << s;

        return 0;
}
