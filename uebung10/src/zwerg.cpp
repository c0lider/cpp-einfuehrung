#include "../include/zwerg.h"
#include "../include/held.h"
#include <iostream>
#include <cmath>


Zwerg::Zwerg() : Held() {

}

Zwerg::Zwerg(std::string name) : Held(name) {

}

Zwerg::Zwerg(std::string name, double groesse, int alter) : Held(name, groesse, alter) {
    
}

std::string Zwerg::getRasse() const {
    return "Zwerg";
}

double Zwerg::lebenspunkteBerechnen() const {
    if (this->get_alter() >= 60) {
        return std::round(this->get_groesse() * 100 * 3);
    }
    return Held::lebenspunkteBerechnen();
}

int Zwerg::getSchaden() const {
    return 100;
}

