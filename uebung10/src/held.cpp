#include "../include/held.h"
#include <iostream>
#include <cmath>


Held::Held() : Held::Held("Max Mustermann") {

}

Held::Held(std::string name) : Held::Held(name, 1.0, 25) {

}

Held::Held(std::string name, double groesse, int alter) {
    this->name = name;
    this->groesse = groesse;
    this->alter = alter;

    this->LP = lebenspunkteBerechnen();
    this->currentLP = this->LP;
}

Held::~Held() {
    std::cout << "Held-Destructor called" << std::endl;
}

std::string Held::get_name() const {
    return this->name;
}

void Held::set_name(std::string newName) {
    this->name = newName;
}

double Held::get_groesse() const {
    return this->groesse;
}

void Held::set_groesse(double groesse) {
    this->groesse = groesse;
    this->LP = lebenspunkteBerechnen();
}

int Held::get_alter() const {
    return this->alter;
}

void Held::set_alter(int newAlter) {
    this->alter = newAlter;
    this->LP = lebenspunkteBerechnen();
} 

double Held::lebenspunkteBerechnen() const {
    if (this->alter >= 0 && this->alter <= 3) {
        return std::round(this->groesse * 100 * 0.1);
    }
    if (this->alter >= 4 && this->alter <= 15) {
        return std::round(this->groesse * 100);
    }
    if (this->alter >= 16 && this->alter <= 60) {
        return std::round(this->groesse * 100 * 2);
    }
    if (this->alter > 60) {
        return std::round(this->groesse * 100 * 1.5);
    }
    return -1;
}

int Held::getLP() const {
    return this->LP;
}

int Held::getCurrentLP() const {
    return this->currentLP;
}

void Held::changeCurrentLP(int x) {
    int newLP = this->currentLP + x;

    if (newLP < 0) {
        this->currentLP = 0;
        return;
    }

    if (newLP > this->LP) {
        this->currentLP = this->LP;
        return;
    }

    this->currentLP = newLP;
}

bool Held::operator==(const Held& otherHeld) const{
    return this->name == otherHeld.name 
            && this->alter == otherHeld.alter 
            && this->groesse == otherHeld.groesse 
            && this->LP == otherHeld.LP;
}

std::ostream& operator<<(std::ostream &output, const Held& held){
    output << held.get_name() << ", Alter: " << held.get_alter() << ", Groesse: " << held.get_groesse() << ", Lebenspunkte: " << held.getCurrentLP() << "/" << held.getLP();
    return output;
}

std::string Held::getRasse() const {
    return "Super duper held";
}

int Held::getSchaden() const {
    return 0;
}

bool Held::getStatus() const {
    return this->currentLP > 0;
}
