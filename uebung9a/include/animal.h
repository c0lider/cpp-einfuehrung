#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
private:
    int age;
    std::string name;
public:
    Animal();
    virtual std::string getType()=0;
    virtual int getLegAmount()=0;
    int getAge() const;
    std::string getName() const;
};

#endif