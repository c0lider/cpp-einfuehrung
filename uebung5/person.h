#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    unsigned short age;
public:
    Person();
    Person(unsigned short age);
    Person(std::string firstName, std::string lastName);
    Person(std::string firstName, std::string lastName, unsigned short age);
    ~Person();

    void output() const;
};

#endif