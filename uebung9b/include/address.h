#ifndef ADDRESS_H
#define ADDRESS_H

#include "person.h"

class Address : public Person {
private:
    std::string street;
    std::string  zipCode;
    std::string city;

public:
    Address();
    void printAddress() const;
    void setStreet(std::string newStreet);
    void setZip(std::string newZip);
    void setCity(std::string newCity);
};

#endif