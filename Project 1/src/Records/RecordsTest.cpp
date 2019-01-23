#include "Records.h"
#include "../Course/Course.h"
#include <iostream>
using namespace std;

int main(){
        vector<Course> courses;
        vector<Student> students;

        courses.push_back(Course("COP3530", "Datastructures and Algorithms", 93.3, 3));
        students.push_back(Student(5252, 3.42, courses, "Grayton Ward", 19));

        courses.push_back(Course("MAP2302", "Differential Equations", 83.2, 3));
        students.push_back(Student(5253, 3.29, courses, "Wrayton Gard", 20));

        Records r(students);

        cout << r;

        return 0;
}
