#include <iostream>
#include <string>
#include <new>

using namespace std;

#ifndef LS_H
#define LS_H

class Node {
public:
  long data; //gespeicherte Information
  Node* next;  //Pointer auf sich selbst
};

class Stack {
public:
  Stack(); 	//NULLpointer wird in C++ einfach mit 0 angegeben
  //wegen der stärkeren Typenprüfung besteht weniger Verwechslungsgefahr zur nummerischen 0
  //in eine bool Abfrage eingesetzt fungiert eine solche 0 wie ein false
  Stack(const Stack& otherStack);
  ~Stack(); //Destruktor (löscht nacheinander alle aufgebauten Knoten)

  //override assignment operator so that a deep copy is performed on assignment
  Stack& operator=(const Stack& other);

  bool push(long item);/*Legt einen neuen Knoten an, weißt d den Wert von item zu und hängt den Knoten an die verkettete Liste*/
  bool pop(long* item); /*Die Information aus dem obersten Knoten wird an der Adresse von item gespeichert. Der oberste Knoten wird gelöscht*/ 
  int get_amount() const { return amount;} /* Informiert über die Anzahl der Knoten in der Liste*/
  long back() const; /*gibt eine Kopie der Information aus dem obersten Knoten aus ohne den Knoten zu löschen.*/
  string asString() const;

private:
  Node* head; //pointer auf den obersten Knoten
  int amount; //anzahl der Knoten
  long default_item; //Hilfsvariable für den Fall, dass leere Knoten gebaut werden sollen.
};
  
#endif 