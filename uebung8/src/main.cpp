#include <iostream>
#include "../include/floor.h"
#include "../include/room.h"
#include "../include/cuboid.h"

int main() {
    Cuboid room;
    room.readIn();
    std::cout << "The room's volume is: " << room.getVolume() << "m^3" << std::endl;
    std::cout << "The cuboid's living space is: " << room.getLivingSpace() << std::endl;
}