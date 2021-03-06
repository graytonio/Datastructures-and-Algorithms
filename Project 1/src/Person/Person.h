#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstdint>
#include <string>

class Person {
protected:
std::string name;
uint8_t age;

public:
Person();
Person(std::string namePar,uint32_t agePar);

const std::string getName();
void setName(const std::string name);

uint8_t getAge();
void setAge(uint8_t age);

friend std ::ostream& operator<<(std::ostream &os, const Person &p);
};
#endif
