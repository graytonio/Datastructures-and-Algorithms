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

        p.setName("Noah Smith");
        cout<<p;

        Person p2("Jane Doeberman", 24);
        cout << p2;

        return 0;
}
