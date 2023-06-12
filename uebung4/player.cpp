#include <iostream>
#include <string>
#include <iomanip>

#include "player.h"

using namespace std;

const string Player::s_playerNameLabel = "Name";
const string Player::s_healthPointsLabel = "Health points";
const string Player::s_energyLabel = "Energy";

int Player::s_defaultHealthPoints = 3;
double Player::s_defaultEnergy = 1.0;

void Player::setHealthPoints(int newHealthPoints) {
    this->healthPoints = newHealthPoints;
}

void Player::setEnergy(double newEnergy) {
    this->energy = newEnergy;
}

bool Player::validateNewEnergy(double potentialEnergy) {
    return potentialEnergy <= 1.0 && potentialEnergy >= 0;
}

string Player::getName() const {
    return this->name;
}

void Player::setName(string newName) {
    this->name = newName;
}

int Player::getHealthPoints() const {
    return this->healthPoints;
}

double Player::getEnergy() const {
    return this->energy;
}

Player::Player(const string name) {
    this->setName(name);
    this->setEnergy(Player::s_defaultEnergy);
    this->setHealthPoints(Player::s_defaultHealthPoints);
}

void Player::printStatus() const {
    cout << "PLAYER STATUS:" << endl;
    cout << setfill('_') << setw(50) << endl; 
    
    cout << setfill(' ') << setw(20) << right << this->s_playerNameLabel << ": ";
    cout << this->getName() << endl;

    cout << setfill(' ') << setw(20) << right << this->s_healthPointsLabel << ": ";
    cout << this->getHealthPoints() << endl;

    cout << setfill(' ') << setw(20) << right << this->s_energyLabel << ": ";
    cout << fixed << setprecision(2) << (this->getEnergy() * 100) << "%" << endl;

    // '\n' necessary for whatever reason
    cout << setfill('_') << setw(50)<< '\n' << '\n';
}

int Player::addHealthPoints(int healthPointsToAdd) {
    this->setHealthPoints(this->getHealthPoints() + healthPointsToAdd);
    return this->getHealthPoints();
}

int Player::loseOneHealthPoint() {
    return this->loseHealthPoints(1);
}

int Player::loseHealthPoints(int healthPointsToLose) {
    this->setHealthPoints(this->getHealthPoints() - healthPointsToLose);

    if (this->getHealthPoints() <= 0) {
        cout << "Game Lost!" << endl;
        this->setHealthPoints(0);
    }
    else {
        cout << "Hp lost!" << endl;
        this->setEnergy(Player::s_defaultEnergy);
    }

    return this->getHealthPoints();
}

void Player::loseEnergy(double lostEnergy) {
    double newEnergyValue = this->getEnergy() - lostEnergy;

    if (!validateNewEnergy(newEnergyValue) || newEnergyValue == 0) {
        this->setEnergy(0);
        this->loseOneHealthPoint();
        return;
    } 

    this->setEnergy(newEnergyValue);
}

void Player::gainEnergy(double gainedEnergy) {
    double newEnergyValue = this->getEnergy() + gainedEnergy;
    if (!validateNewEnergy(newEnergyValue)) {
        this->setEnergy(1);
        return;
    }
    this->setEnergy(newEnergyValue);
}
