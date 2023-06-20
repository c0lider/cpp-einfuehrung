#include <iostream>
#include "long_stack.h"

Stack::Stack() {
    amount = 0;
    head = NULL;
}

// Copy constructor neccessary because we have to deep copy all nodes
Stack::Stack(const Stack& otherStack) {
    Node* currentNode = otherStack.head;
    Stack tempStack;

    while (currentNode != NULL) {
        tempStack.push(currentNode->data);
        currentNode = currentNode->next;
    }

    //reverse temp Stack
    currentNode = tempStack.head;
    while (currentNode != NULL) {
        this->push(currentNode->data);
        currentNode = currentNode->next;
    }
}

Stack::~Stack() {
    std::cout << "Deleting stack" << std::endl;
    long poppedItem;

    while (this->pop(&poppedItem));
}

// chatGPT says this is not correct although it works perfectly fine..
Stack& Stack::operator=(const Stack& other) {
    if (this == &other) {
        return *this;
    }
    Stack deepCopy{other};

    return deepCopy;
}

// pushes the item onto the stack and returns true?
bool Stack::push(long item) {
    // it's necessary to allocate memory with new because otherwise node will be deleted after leaving code block
    Node* node = new Node{item, head};
    node->next = head;
    head = node;
    
    amount++;
    return true;
}

// returns false if there are no items on the stack
bool Stack::pop(long* item) {
    if (amount == 0) {
        return false;
    }

    Node* newHead = head->next;
    *item = head->data;
    delete(head);
    head = newHead;
    amount--;
    return true;
}

long Stack::back() const {
    if (amount > 0) {
        return head->data;
    }
    return NULL;
}

string Stack::asString() const{
    Node* currentNode = head;
    int arrayCounter = amount;
    long values[amount];
    
    while (currentNode != NULL) {
        values[arrayCounter - 1] = currentNode->data;
        currentNode = currentNode->next;
        arrayCounter--;
    }

    string stackAsString = "";
    
    for (int i=amount - 1; i>=0; i--) {
        stackAsString.append(std::to_string(values[i]));
        stackAsString.append(" ");
    }

    return stackAsString;
}





