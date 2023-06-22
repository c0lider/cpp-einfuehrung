#include <iostream>
#include "../include/floor.h"


double Floor::getWidth() const {
    return this->width;
}

double Floor::getLength() const {
    return this->length;
}

std::string Floor::getFlooring() const {
    return this->flooring;
}

double Floor::getSurfaceArea() const {
    return this->getWidth() * this->getLength();
}

void Floor::readIn() {
    std::cout << "Reading in the floor's dimensions." << std::endl;
    readInWidth();
    readInLength();
    readInFlooring();
}

/**
 * @throws std::invlaid_argument if a value <= 0.0 is provided
*/
void Floor::setWidth(double newWidth) {
    if (newWidth <= 0.0) {
        throw std::invalid_argument("Width must be > 0.0");
    }
    this->width = newWidth;
}

/**
 * @throws std::invlaid_argument if a value <= 0.0 is provided
*/
void Floor::setLength(double newLength) {
    if (newLength <= 0.0) {
        throw std::invalid_argument("Length must be > 0.0");
    }
    this->length = newLength;
}

void Floor::setFlooring(std::string newFlooring) {
    this->flooring = newFlooring;
}

void Floor::readInWidth() {
    double inputValue;

    while (true) {    
        std::cout << "Please type in the room's width:\t";
        std::cin >> inputValue;
        try {
            this->setWidth(inputValue);
            break;
        }
        catch(std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    };
}

void Floor::readInLength() {
    double inputValue;

    while (true) {    
        std::cout << "Please type in the room's length:\t";
        std::cin >> inputValue;
        try {
            this->setLength(inputValue);
            break;
        }
        catch(std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    };
}

void Floor::readInFlooring() {
        std::string inputValue;

        std::cout << "Please type in the floor's material:\t";
        std::getline(std::cin, inputValue);

        this->setFlooring(inputValue);
}
