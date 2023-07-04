#include "../include/address.h"

Address::Address() : Person() {
    std::cout << "Please type in your street:\t";
    std::cin >> street;

    std::cout << "Please type in your zip code:\t";
    std::cin >> zipCode;

    // TODO "New York" for example (more than one word names)
    std::cout << "Please type in your city:\t";
    std::cin >> city;
}

void Address::printAddress() const {
    std::cout << "Street: " << this->street << std::endl;
    std::cout << "Zip code: " << this->zipCode << std::endl;
    std::cout << "City: " << this->city << std::endl;
} 

void Address::setStreet(std::string newStreet) {
    this->street = newStreet;
}

void Address::setZip(std::string newZip) {
    this->zipCode = newZip;
}

void Address::setCity(std::string newCity) {
    this->city = newCity;
}