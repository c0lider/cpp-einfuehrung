#include <iostream>
#include "../include/animal.h"
#include "../include/cat.h"
#include "../include/gull.h"
#include "../include/snake.h"
#include "../include/spider.h"

void identify(Animal *animal) {
    std::cout << animal->getName() << " is a " << animal->getType() << ", has ";
    std::cout << animal->getLegAmount() << " legs and is " << animal->getAge() << " years old." << std::endl;
}


int main() {
    Animal* genericAnimal = new Cat;
    identify(genericAnimal);

    genericAnimal = new Gull;
    identify(genericAnimal);

    genericAnimal = new Snake;
    identify(genericAnimal);

    genericAnimal = new Spider;
    identify(genericAnimal);


}