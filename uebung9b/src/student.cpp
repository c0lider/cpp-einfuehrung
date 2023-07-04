#include "../include/student.h"

Student::Student() : Person() {
    std::cout << "Please type in your matrikel number:\t";
    std::cin >> matrikelNo;
}

void Student::printMatrikelNo() const {
    std::cout << "Matrikel #: " << this->matrikelNo << std::endl;
}