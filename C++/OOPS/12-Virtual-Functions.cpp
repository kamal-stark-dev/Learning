// Virtual Function - It's a member function in the base class that can be overridden in derived class.

#include <iostream>
using namespace std;

// Virtual functions are a key part of polymorphism, they let different objects respond differently to the same function call.

/*
Why use Virtual Functions?
> Without virtual functions, C++ decides which function to call based on the pointer type, not the actual object type that's being passed.

To put it more simply: (Note: we are passing object as a pointer)
    Without virtual -> the base runs, even if the object if from child class.
    With virtual -> the child's version runs, as expected.
*/

class Animal {
public:
    void whatami() {
        cout << "Animal.\n";
    }
    virtual void sound() {
        cout << "Animal Sound!\n";
    }
};

class Pig : public Animal {
public:
    void whatami() {
        cout << "Pig.\n";
    }
    void sound() override {
        cout << "Oink oink!\n";
    }
};

int main(void) {
    Animal* myAnimal;
    Pig myPiggy;

    myAnimal = &myPiggy; // point the base class (Animal) pointer to the derived class object (Pig)

    myAnimal->whatami(); // this will say "Animal" not "Pig" as we didn't use virutal function
    myAnimal->sound(); // this will output "Oink oink!"

    return 0;
}

/*
Note: Use `virtual` only in base class and use `override` keyword (optional, but recommended) in the derived class.

`->` operator -> is used to access members through an object pointer.
It's shortcut way of writing `(*pointer).member`

```
Animal* animal;
animal->sound(); // same as (*animal).sound();
```
*/