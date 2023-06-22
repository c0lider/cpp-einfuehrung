#ifndef ROOM_H
#define ROOM_H

#include "floor.h"

class Room : public Floor {
private: 
    double height;
public:
    double getHeight() const;
    virtual double getVolume() const;
    void readIn() override;
private:
    void setHeight(double newHeight);
    void readInHeight();
};

#endif