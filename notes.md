# Notes for Object Oriented Programming in C++

# Vocabulary and other small notes
- member function = method (function that operates on objects)
- `~`on a mac keyboard -> [option] + n
- `using namespace std;` is considered a bad practice
- use the `-std=c++11` command parameter to compile using c++ 11

# Code snippets

## Constructor overloading
```c++
class MyClass {
public:
    MyClass() {
        // Default constructor
    }
    
    MyClass(int value) {
        // Constructor with an integer parameter
    }
    
    MyClass(int value1, int value2) {
        // Constructor with two integer parameters
    }
};
```

```c++
class MyClass {
public:
    MyClass(int value1 = 0, int value2 = 0) {
        // Constructor with default arguments
    }
};
```
> Default values in functions (/constructors) have to be at the end of the parameter list

```c++
class MyClass {
public:
    MyClass() : MyClass(0) {
        // Delegating constructor
    }
    
    MyClass(int value) {
        // Constructor with an integer parameter
    }
};
```
> Starting with c++ 11 it is possible to call one constructor from another one using the above syntax.

```c++
class MyClass {
private:
    int number;
    double& doubleRef;
public:
    MyClass(int value) : number(value), doubleRef(number) {
        // Constructor with an integer parameter
    }
    
    MyClass(double& reference) : number(0), doubleRef(reference) {
        // Constructor with a reference parameter
    }
};

```
> It is possible to directly initialize non-static or reference members before going into the constructor body via the above syntax.

## Ways to instantiate a class
```c++
MyClass obj;  // Object created on the stack (i.e. the object is automatically deleted after leaving its scope)

MyClass* obj = new MyClass();  // Object created on the heap, needs to be deleted()

static MyClass obj;  // Object with static storage duration, is created once the program starts and remains in memory until program terminates
```
> If an class is instantiated using the `new`operator, its member functions have to be called using the `->` operator, since it provides a pointer to the created class instance.

## 

# Makefile
If no argument is passed to the `make` command, the first entry will be executed.