#ifndef COP3530_PERSON_H
#define COP3530_PERSON_H
#include <iostream>
#include <cstdint>
#include <string>

class Person {
private:
std::string name;
uint8_t age;

public:
Person();
Person(std::string namePar,uint32_t agePar);
const std::string &getName();
void setName(const std::string &name);
uint8_t getAge();
void setAge(uint8_t age);
friend std ::ostream& operator<<(std::ostream &os, const Person &p);
};
#endif //COP3530_PERSON_H
