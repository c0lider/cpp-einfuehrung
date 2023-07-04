#include "../include/person.h"
#include "../include/student.h"
#include "../include/address.h"

#include <iostream>

int main() {
    Address* person = new Address();
    person->printName();
    person->printAddress();
}