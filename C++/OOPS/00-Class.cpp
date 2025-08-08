// Class - Basic Building Block of OOPS, it's a user defined data type that acts like a blueprint to create objects that have similar properties(data) and behaviours(functions).

// Example - You have a `Student` class with properties like name, age, rollno and behaviours like greet(), study() etc.

#include <iostream>
using namespace std;

class Student {
public: // access specifier
    string name;
    int age;
    string rollno;

    void greet() {
        cout << "Hello there. I am " << name << "\n";
    }

    void study(int n) {
        cout << name << " studied for " << n << " hours.\n";
    }
};

// Object - an object is a real, usable instance of a class that has the specified properties and behaviours.
// Note: When you define a class no memory is used, but when you declare an object of that class, required memory is allocated to it.

int main(void) {
    Student s; // `s` is an object of class `Student`
    s.name = "Jake"; // name, age, rollno are attributes
    s.age = 20;
    s.rollno = "JK-301";

    s.greet(); // greet and study are methods
    s.study(2);

    return 0;
}

// https://www.geeksforgeeks.org/cpp/object-oriented-programming-in-cpp/