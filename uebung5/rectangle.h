#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double width, double height);

    void printInfo() const;

    void printCircumfenceAndArea() const;

    void printToConsole(char printChar) const;

    double getArea() const;
    double getCircumfence() const;

    void setWidth(double width);
    double getWidth() const;

    double getHeight() const;
    void setHeight(double height);
};

#endif