#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>


class Floor {
private:
    double width;
    double length;
    std::string flooring;

public:
    double getWidth() const;
    double getLength() const;
    std::string getFlooring() const;
    double getSurfaceArea() const;

    virtual void readIn();

private:
    void setWidth(double newWidth);
    void setLength(double newLength);
    void setFlooring(std::string newFlooring);
    void readInWidth();
    void readInLength();
    void readInFlooring();
};

#endif
