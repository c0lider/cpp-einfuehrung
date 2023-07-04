#include "../include/person.h"

Person::Person() {
    std::string enteredFirstName;
    std::string enteredLastName;

    std::cout << "Please type in your first and last name: ";
    std::cin >> firstName;
    std::cin >> lastName;
}

std::string Person::getFirstName() const {
    return this->firstName;
}

std::string Person::getLastName() const {
    return this->lastName;
}

void Person::printName() const {
    std::cout << "First name: " << this->getFirstName() << std::endl;
    std::cout << "Last name: " << this->getLastName() << std::endl;
}

void Person::setFirstName(std::string newFirstName) {
    this->firstName = newFirstName;
} 

void Person::setLastName(std::string newLastName) {
    this->lastName = newLastName;
}
