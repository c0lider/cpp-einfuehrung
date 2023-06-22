#ifndef CUBOID_H
#define CUBOID_H

#include "../include/room.h"

class Cuboid : public Room {
public:
    double getLivingSpace() const;
};

#endif