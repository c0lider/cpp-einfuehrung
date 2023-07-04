#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person {
private:
    std::string matrikelNo;
public:
    Student();
    void printMatrikelNo() const;
};

#endif