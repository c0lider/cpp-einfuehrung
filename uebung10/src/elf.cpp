#include "../include/elf.h"
#include "../include/held.h"


Elf::Elf() : Held() {

}

Elf::Elf(std::string name) : Held(name) {

}

Elf::Elf(std::string name, double groesse, int alter) : Held(name, groesse, alter) {
    
}

std::string Elf::getRasse() const {
    return "Elf";
}

int Elf::getSchaden() const {
    return 150;
}
