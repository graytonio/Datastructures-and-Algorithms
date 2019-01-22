#include <iostream>
#include "Person.h"
using namespace std;

int main(){
        Person p("John Doe", 38);
        cout<<p;

        p.setName("Jane Doe");
        cout<<p;

        p.setAge(24);
        cout<<p;

        p.setName("Noah Dickwad");
        cout<<p;

        return 0;
}
