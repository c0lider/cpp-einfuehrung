# Notes for Object Oriented Programming in C++

# Vocabulary and other small notes
- member function = method (function that operates on objects)
- `~` on a mac keyboard -> [option] + n
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

## The Copy Constructor
In C++ there is a so called "copy constructor", that allows for shallow object copies. It copies all member variables from the original object to the newly created one and uses the following syntax:
```c++
MyObject originalObj{param1, param2};
MyObject copiedObj{originalObj};
```
>***Important:*** By deafult it only creates a shallow copy and causes trouble with dynamically allocated memory and pointers.

```c++
MyClass(const MyClass& otherMyClassObject) {
    // implementation of copy constructor
}
```


## Ways to instantiate a class
```c++
MyClass obj;  // Object created on the stack (i.e. the object is automatically deleted after leaving its scope)

MyClass* obj = new MyClass();  // Object created on the heap, needs to be deleted()

static MyClass obj;  // Object with static storage duration, is created once the program starts and remains in memory until program terminates
```
> If an class is instantiated using the `new`operator, its member functions have to be called using the `->` operator, since it provides a pointer to the created class instance.

## Friend keyword
The friend keyword grants the `FriendClass` access to its private and protected members. It usually is not needed and considered bad practice to use it.
```c++
class MyClass {
private:
    int privateData;

public:
    friend class FriendClass;  // Declaration of a friend class
};

```

## Raw-Strings

```c++
char* multiLineString = R"(Escape symbols like \n will be ignored.
Instead "real" line breaks will be used and it is even possible to use 
quotation marks inside raw strings.)";
```
>Available in c++11 or higher.

## Access Modifier
This is the preferred order for public and private methods and members.
```c++
class Example {
private: 
    int privateInt;
    // ...
public:
    int publicInt;
    //...
public:
    void publicMethod() {
        //...
    }
private:
    void privateMethod() {
        //...
    }
}
```

## Operator overloading
```c++
class MyClass{
public:
    MyClass& operator=(const MyClass& other);
    
    bool operator>(const MyClass& other) const;
    bool operator>=(const MyClass& other) const;
    bool operator<(const MyClass& other) const;
    bool operator<=(const MyClass& other) const;
    
    friend std::istream& operator>>(std::istream& input, MyClass& myObj);
    friend std::ostream& operator<<(std::ostream& output, const MyClass& myObj);
}
```

## Inheritance
To create a derived class in C++, you use the colon (:) followed by the access specifier (public, protected, or private) and the base class name. The access specifier determines the visibility of the base class members in the derived class.

```c++
class DerivedClass: access-modifier BaseClass {

};
```

You can call methods from the base class using the following syntax:
```c++
class Derived : public Base {
public:
    void derivedMethod() {
        Base::baseMethod();
        // ...
    }
}
```


## Overriding and virtual methods
The following code segments will show the difference between using the keyword `virtual` and not using it when overriding methods:

```c++
class Base {
public:
    // WITH virtual
    virtual void method() {
        cout << "Base::method()" << endl;
    }
};

class Derived : public Base {
public:
    void method() override {
        cout << "Derived::method()" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->method();  // Prints "Derived::method()"
}

```

```c++
class Base {
public:
    // WITHOUT virtual
    void method() {
        cout << "Base::method()" << endl;
    }
};

class Derived : public Base {
public:
    void method() {
        cout << "Derived::method()" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->method();  // Prints "Base::method()"
}
```
> The `override` keyword is only needed in the definition but not the implementation!

# Makefile
- If no argument is passed to the `make` command, the first entry will be executed.
- On windows machines the convention is to name the file "Makefile" with a capital 'M'. Otherwise use a lower case 'm'