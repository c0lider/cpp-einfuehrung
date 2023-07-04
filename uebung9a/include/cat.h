#ifndef CAT_H
#define CAT_H

#include "animal.h"
#include <iostream>

class Cat : public Animal {
    std::string getType();
    int getLegAmount();
};

#endif