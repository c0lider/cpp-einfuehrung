#ifndef SNAKE_H
#define SNAKE_H

#include "animal.h"
#include <iostream>

class Snake : public Animal {
    std::string getType();
    int getLegAmount();
};

#endif