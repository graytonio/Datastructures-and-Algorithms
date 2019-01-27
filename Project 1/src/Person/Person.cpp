#include "Person.h"
using namespace std;

//Default Constructor
Person::Person() {

}

//Base Constructor
Person::Person(std::string namePar, uint32_t agePar) {
        name=namePar;
        age=agePar;
}

//Name Getter
const string Person::getName()  {
        return name;
}

//Name Setter
void Person::setName(const string name) {
        Person::name = name;
}

//Age Getter
uint8_t Person::getAge()  {
        return age;
}

//Age setter
void Person::setAge(uint8_t age) {
        Person::age = age;
}

//Cout Operator Definition
ostream& operator<<(ostream& os, const Person &p)
{
        os << "Name: " << p.name << "\nAge: " << unsigned(p.age) <<endl;
        return os;
}
