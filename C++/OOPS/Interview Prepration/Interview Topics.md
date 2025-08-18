1. Core Principles

1.1 Classes and Objects - A class is like a blueprint, while and object is the house built from it. A class define the properties (attributes) and behaviours (methods), while an object is a specific instance of that class.

```cpp
#include <iostream>
using namespace std;

class Car {               // Class (blueprint)
public:
    string model;
    void drive() {
        cout << model << " is driving" << endl;
    }
};

int main() {
    Car c1;               // Object (instance)
    c1.model = "Tesla";
    c1.drive();           // Output: Tesla is driving
    return 0;
}
```

1.2 Encapsulation - Building data and related methods together but direct access to the members is restricted and special methods are made to access the members of the encapsulated class.
Example: using getter and setter function to change some attribute rather than directly allowing it's access publically.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;   // Hidden data

public:
    BankAccount() : balance(0) {}

    void deposit(double amount) { // setter
        balance += amount;
    }
    double getBalance() { // getter
        return balance;
    }
};
```

1.3 Abstraction - Only showing the necessary details and hiding the unecessary details. Access specifiers - public, private and protected are the main pillar for abstraction.
Example: A chat application user just need the functionality of sending and receiving messages but not their implementaion (they need not to know the inner workings).

```cpp
#include <iostream>
using namespace std;

class Shape {            // Abstract base class
public:
    virtual void draw() = 0;   // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};
```

1.4 Inheritance - Mechanism where a class derives properties and behaviours from another class.
Example: If class B is derived from class A then you can access public and protected members of class A from class B.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Animal eats" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

// Dog object can also access the function `eat()`.
```

1.5 Polymorphism - Ability of same methods or inheritance to take on different forms through overloading or overriding.

(a) Overloading - Compile Time Polymorphism

```cpp
#include <iostream>
using namespace std;

class MathUtils {
public:
    int multiply(int a, int b) {
        return a * b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
};
```

(b) Overriding - Run Time Polymorphism

```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() {
        cout << "Vehicle starts" << endl;
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike starts with a kick" << endl;
    }
};

int main() {
    Vehicle* v = new Bike();
    v->start();    // Output: Bike starts with a kick
    delete v;
    return 0;
}
```

More on - https://www.geeksforgeeks.org/interview-prep/oops-interview-questions/
