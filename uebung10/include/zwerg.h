#ifndef ZWERG_H
#define ZWERG_H

#include "held.h"
#include <iostream>

class Zwerg : public Held {
private:
public:
    Zwerg();
    Zwerg(std::string name);
    Zwerg(std::string name, double groesse, int alter);
    
    std::string getRasse() const override;
    double lebenspunkteBerechnen() const override;
    int getSchaden() const override;
};

#endif