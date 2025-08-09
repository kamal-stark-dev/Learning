// Multiple Inheritance - A class can be derived from more than one base class, using a comma-separated list.

#include <iostream>
using namespace std;

// base class 1
class MyClass_1 {
public:
    void function_1() {
        cout << "This is a function from parent class 1.\n";
    }
};

// base class 2
class MyClass_2 {
public:
    void function_2() {
        cout << "This is a function from parent class 2.\n";
    }
};

// Multiple Inheritance
class Derived: public MyClass_1, public MyClass_2 {};

int main(void) {
    Derived myObj;

    myObj.function_1();
    myObj.function_2();

    return 0;
}