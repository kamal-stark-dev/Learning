// Polymorphism - It means "many forms", and it occurs when we have many classes that are realated to each other by inheritance. Polymorphism allows inherited methods to perform different tasks, allowing us to perform a single action in different ways.

#include <iostream>
using namespace std;

class Animal {
public:
    void makeSound() {
        cout << "Animal makes a sound.\n";
    }
};

class Pig : public Animal {
public:
    void makeSound() {
        cout << "Oink oink!\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "Woof woof!\n";
    }
};

int main(void) {
    Animal myAnimal;
    Pig myPiggy;
    Dog myPup;

    myAnimal.makeSound();
    myPiggy.makeSound();
    myPup.makeSound();

    return 0;
}

// Polymorphism allows us to personalize methods for inherited classes.