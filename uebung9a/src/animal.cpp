#include "../include/animal.h"
#include <iostream>

Animal::Animal()  {
    std::cout << "Enter your animal's name: ";
    // std::getline(std::cin, name);
    std::cin >> name;

    std::cout << "Enter your animal's age: ";
    std::cin >> age;
}

int Animal::getAge() const
{
    return this->age;
}

std::string Animal::getName() const {
    return this->name;
}