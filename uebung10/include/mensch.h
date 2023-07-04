#ifndef MENSCH_H
#define MENSCH_H

#include "held.h"

class Mensch : public Held {
private:
public:
    Mensch();
    Mensch(std::string name);
    Mensch(std::string name, double groesse, int alter);
    
    std::string getRasse() const override;
    double lebenspunkteBerechnen() const override;
    int getSchaden() const override;
};

#endif