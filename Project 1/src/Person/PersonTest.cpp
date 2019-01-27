#include <iostream>
#include "Person.h"
using namespace std;

int main(){
        Person p("John Doe", 38); //Create a Person Object
        cout<<p;

        p.setName("Jane Doe"); //Set the Name of the Person
        cout<<p;

        p.setAge(24); //Set the Age of the Person
        cout<<p;

        p.setName("Noah Smith"); //Set the Name of the Person
        cout<<p;

        Person p2("Jane Doeberman", 24); //Create a secord Person Object
        cout << p2;

        return 0;
}
