#ifndef ELF_H
#define ELF_H

#include "held.h"
#include <iostream>

class Elf : public Held {
private:
public:
    Elf();
    Elf(std::string name);
    Elf(std::string name, double groesse, int alter);
    
    std::string getRasse() const override;
    int getSchaden() const override;
};

#endif