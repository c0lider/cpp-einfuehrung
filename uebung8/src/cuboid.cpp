#include <iostream>
#include "../include/cuboid.h"

double Cuboid::getLivingSpace() const {
    if (this->getHeight() < 2.0) {
        return 0.5 * this->getSurfaceArea();
    }

    if (this->getHeight() < 1.0) {
        return 0;
    }
    
    return this->getSurfaceArea();
}