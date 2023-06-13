#include <iostream>
#include <string>

#include "person.h"

Person::Person() : Person("Xaviette", "Morgentau", 99){
    // no body allowed
}
Person::Person(unsigned short age) : Person("Xaviette", "Morgentau", age){

}

Person::Person(std::string firstName, std::string lastName) : Person(firstName, lastName, 99) {

}

Person::Person(std::string firstName, std::string lastName, unsigned short age) : firstName(firstName), lastName(lastName), age(age)
{
}

// destructor not necessary since the compiler autogenerates a sufficient one 
// since the class does not hold any dynamically allocated resources
Person::~Person() {
    
}


void Person::output() const {
    std::cout << "Person " << firstName << " " << lastName << " is " << age << " years old." << std::endl;
}