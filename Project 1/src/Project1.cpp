#include <iostream>
#include "Person/Person.h"
#include "Course/Course.h"

using namespace std;

int main(){
        Person p("John Doe", 38);
        cout<<p;

        Course c("COP3530", "Datastructures and Algorithms", 93.3, 3);
        cout << c;

        return 0;
}
