#ifndef SLOPE_H
#define SLOPE_H

#include "../include/room.h"

class Slope : Room {
public:
    double getVolume() const override;
    double getLivingSpace() const;
private:

};

#endif