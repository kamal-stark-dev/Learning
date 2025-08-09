// Inheritance - It allows one class to use attributes and methods from another class. It helps you write clearn and more efficient code by avoiding duplication.

#include <iostream>
using namespace std;

/*
To inherit from a class `:` symbol is used.

Inheritance consists of:
    1. Derived Class (child) - the class that inherits from another class
    2. Base Class (parent) - the class from which we are inheriting
*/

// base class
class Vehicle {
public:
    string brand = "Ford";
    void honk() {
        cout << "Tuut, tuut!\n";
    }
};

// derived class
class Car: public Vehicle {
public:
    string model = "Mustang";
};

int main(void) {
    Car myCar;
    cout << "Model: " << myCar.model << "\nBrand: " << myCar.brand << "\n";
    myCar.honk();

    return 0;
}

// As you can see we accessed brand and honk method without declaring them again in the `Car` class because of inheritance.