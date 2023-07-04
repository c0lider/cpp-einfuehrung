#include "../include/mensch.h"
#include "../include/held.h"

Mensch::Mensch() : Held() {

}

Mensch::Mensch(std::string name) : Held(name) {

}

Mensch::Mensch(std::string name, double groesse, int alter) : Held(name, groesse, alter) {
    
}

std::string Mensch::getRasse() const {
    return "Mensch";
}

double Mensch::lebenspunkteBerechnen() const {
    return Held::lebenspunkteBerechnen() + 30;
}

int Mensch::getSchaden() const {
    return 120;
}
