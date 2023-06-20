#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
private:
    double width;
    double height;
    static int count;

public:
    Rectangle();
    Rectangle(double width, double height);

    bool operator>(const Rectangle& otherRect) const;
    bool operator>=(const Rectangle& otherRect) const;
    bool operator<(const Rectangle& otherRect) const;
    bool operator<=(const Rectangle& otherRect) const;

    friend std::istream& operator>>(std::istream& input, Rectangle& rectangle);
    friend std::ostream& operator<<(std::ostream& output, const Rectangle& rectangle);

    static int getCount();
    
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