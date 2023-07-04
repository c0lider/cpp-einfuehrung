#ifndef GULL_H
#define GULL_H

#include "animal.h"
#include <iostream>

class Gull : public Animal {
    std::string getType();
    int getLegAmount();
};

#endif