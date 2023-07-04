#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
private:
    std::string firstName;
    std::string lastName;

public:
    Person();
    
    std::string getFirstName() const;
    std::string getLastName() const;
    void printName() const;
    void setFirstName(std::string newFirstName);
    void setLastName(std::string newLastName);
};

#endif