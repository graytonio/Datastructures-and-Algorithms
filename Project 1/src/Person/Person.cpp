#include "Person.h"
using namespace std;

const string Person::getName()  {
        return name;
}
void Person::setName(const string name) {
        Person::name = name;
}
uint8_t Person::getAge()  {
        return age;
}
void Person::setAge(uint8_t age) {
        Person::age = age;
}
Person::Person() {
}
Person::Person(std::string namePar, uint32_t agePar) {
        name=namePar;
        age=agePar;
}
ostream& operator<<(ostream& os, const Person &p)
{
        os << "Name: " << p.name << "\nAge: " << unsigned(p.age) <<endl;
        return os;
}
