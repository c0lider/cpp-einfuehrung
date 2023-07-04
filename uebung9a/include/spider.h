#ifndef SPIDER_H
#define SPIDER_H

#include "animal.h"
#include <iostream>

class Spider : public Animal {
    std::string getType();
    int getLegAmount();
};

#endif