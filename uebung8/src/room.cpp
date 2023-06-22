#include <iostream>
#include "../include/room.h"

double Room::getHeight() const {
    return this->height;
}

double Room::getVolume() const {
    return this->getWidth() * this->getLength() * this->getHeight();
}

void Room::readIn() {
    Floor::readIn();
    this->readInHeight();
}

void Room::setHeight(double newHeight) {
    if (newHeight < 1.0) {
        throw std::invalid_argument("The height must be at least 1m!");
    }
    this->height = newHeight;
} 

void Room::readInHeight() {
    double inputValue;

    while (true) {    
        std::cout << "Please type in the room's height:\t";
        std::cin >> inputValue;
        try {
            this->setHeight(inputValue);
            break;
        }
        catch(std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    };
}