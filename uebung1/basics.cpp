// standard io
#include <iostream>
// for getline()
#include <string>
// for numbers (setprecision(2))
#include <iomanip>
// for 'new'
#include <new>


int greetUser();
int printDouble();
int printInt();
int useNew();

int main() {
    greetUser();
    printDouble();
    printInt();
    useNew();
}

int greetUser() {
    std::string test = "";
    std::cout << "Please enter your name: ";
    // cuts off the string at the given delimiter char, but you can enter text until the return key is pressed
    getline(std::cin, test, ' ');

    std::cout << std::endl;

    std::cout << "Hello, " << test << "!" << std::endl;
}

int printDouble() {
    double myDouble = 123.456;

    std::cout << std::setprecision(4) << myDouble << std::endl;

    return 0;
}

int printInt() {
    int myInt = 1234;

    // print int as hex number
    std::cout << std::hex << myInt << std::endl;

    // show base for the given number
    std::cout << std::showbase << std::hex << myInt << std::endl;

    // set number to be an octal
    std::cout << std::oct << myInt << std::endl;

    // remove base in front of number
    std::cout << std::noshowbase << myInt << std::endl;

    // convert number back to decimal
    std::cout << std::dec << myInt << std::endl;

    // show '+' in front of positive integers
    std::cout << std::showpos << myInt << std::endl;

    return 0;
}

int useNew() {
    long* number = new long;

    // prints pointer address
    std::cout << number << std::endl;

    // reserve memory for 5 long numbers
    long* fiveNumbers = new long[5];

    // like free() in c
    delete[] fiveNumbers;

    return 0;
}