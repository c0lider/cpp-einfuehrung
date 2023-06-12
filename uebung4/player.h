#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
    static const std::string s_playerNameLabel;
    static const std::string s_healthPointsLabel;
    static const std::string s_energyLabel;

    static int s_defaultHealthPoints;
    static double s_defaultEnergy;

    std::string name;
    int healthPoints;
    double energy;

    void setHealthPoints(int newHealthPoints);
    void setEnergy(double newEnergy);
    static bool validateNewEnergy(double potentialEnergy);

    std::string getName() const;
    void setName(std::string newName);
    int getHealthPoints() const;
    double getEnergy() const;

public:
    // default parameters belong into declaration, not implementation (->header file)
    Player(std::string name = "Xaviette Morgentau");

    void printStatus() const;
    int addHealthPoints(int healthPointsToAdd);
    int loseOneHealthPoint();
    int loseHealthPoints(int healthPointsToLose);
    void loseEnergy(double lostEnergy);
    void gainEnergy(double gainedEnergy);
};

#endif
