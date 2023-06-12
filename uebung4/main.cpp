#include "player.h"
#include <iostream>

int main() {
    // if no args are passed to constructor, don't use parantheses
    Player player;
    player.printStatus();
    
    player.gainEnergy(10);
    player.printStatus();

    player.loseEnergy(0.5);
    player.printStatus();

    player.gainEnergy(1.5);
    player.printStatus();

    player.loseEnergy(1.5);
    player.printStatus();
    
    player.addHealthPoints(2);
    player.printStatus();

    player.loseHealthPoints(3);
    player.printStatus();

    player.loseHealthPoints(3);
    player.printStatus();    
}