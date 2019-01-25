#include "Student.h"
#include <iostream>
using namespace std;

int main(){
        vector<Course> courses;
        courses.push_back(Course("COP3530", "Datastructures and Algorithms", 93.3, 3));
        Student s(5252, 3.42, courses, "Grayton Ward", 19);
        s.addCourse(Course("MAP2302", "Differential Equations", 87.2, 3));
        cout << s;
        return 0;
}
