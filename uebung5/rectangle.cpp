#include <iostream>
#include <iomanip>

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
}

void Rectangle::printInfo() const {
    cout << "Rectangle width: "<< width << "cm height : " << height << endl;
    cout << "Sketch:" << endl;
    printToConsole('#');
}

void Rectangle::printCircumfenceAndArea() const {
    cout << "Circumfence " << ": " << getCircumfence() << "cm" << endl;
    cout << "Area " << ": " << getArea() << "cm^2" << endl;
}

void Rectangle::printToConsole(char printChar) const {
    cout << setfill(printChar);
    cout << setw(getWidth()) << "" << endl;

    for (int i = 0; i < getHeight() - 2; i++) {
        cout << setfill(' ') << setw(getWidth() - 1) << left << printChar << right << printChar << endl;
    }

    if ((int)getHeight() > 1) {
        cout << setfill(printChar);
        cout << setw(getWidth()) << "" << endl;
    }
    cout << endl;
}

double Rectangle::getArea() const {
    return height * width;
}

double Rectangle::getCircumfence() const {
    return 2 * height + 2 * width;
}

double Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(double width) {
    if (width <= 0) {
        cout << "A rectangles width must be positive" << endl;
        return;
    }
    this->width = width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(double height) {
    if (height <= 0) {
        cout << "A rectangles height must be positive" << endl;
        return;
    }
    this->height = height;
}