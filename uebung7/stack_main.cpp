#include <iostream>
#include "long_stack.h"

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    Stack stackCopy = stack;
    stackCopy.push(4);
    stackCopy.push(5);
    stackCopy.push(6);

    std::cout << "Initial amount of objects on original stack: \t" << stack.get_amount() << std::endl;
    std::cout << "Original stack:\t" << stack.asString() << std::endl;
    std::cout << "Initial amount of objects on copied stack: \t" << stackCopy.get_amount() << std::endl;
    std::cout << "Copied stack:\t" << stackCopy.asString() << std::endl;

    // init a long variable and pass its pointer to pop()
    long poppedItem;
    int amountOfPoppedItems = 0;

    while (stack.pop(&poppedItem)) {
        amountOfPoppedItems++;
        std::cout << "Removed item no. " << amountOfPoppedItems << " from original stack: '" << poppedItem << "'" << std::endl;
    }

    std::cout << "Amount of objects on original stack after popping all: " << stack.get_amount() << std::endl;
    
    if (stack.push(69)) {
        std::cout << "After pushing '69' the original stack's head is: '" << stack.back() << "'" << std::endl;
    }

    std::cout << "Final amount of objects on original stack: \t" << stack.get_amount() << std::endl;
    std::cout << "Original stack:\t" << stack.asString() << std::endl;
    std::cout << "Final amount of objects on copied stack: \t" << stackCopy.get_amount() << std::endl;
    std::cout << "Copied stack:\t" << stackCopy.asString() << std::endl;
}
