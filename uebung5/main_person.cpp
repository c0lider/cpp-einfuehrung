#include "person.h"

int main() {
    Person* person = new Person();
    person->output();

    person = new Person("Max", "Mustermann");
    person->output();

    person = new Person(69);
    person->output();

    person = new Person("Erika", "Mustermann", 42);
    person->output();
}