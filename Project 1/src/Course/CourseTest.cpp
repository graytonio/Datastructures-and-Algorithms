#include "Course.h"
using namespace std;

int main(){
        //Create a Course
        Course c("COP3530", "Datastructures and Algorithms", 93.3, 3);
        cout << c;

        //Set the Course Code
        c.setCode("MAP2302");
        cout << c;

        //Set Course Title
        c.setTitle("Differential Equations");
        cout << c;

        //Set Course Grade
        c.setGrade(92.5);
        cout << c;

        //Set Credit Hours
        c.setCreditHour(4);
        cout << c;

        return 0;
}
