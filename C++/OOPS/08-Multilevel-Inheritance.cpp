// Multilevel Inheritance - A class can also be derived from a class, which is already derived from another class.

#include <iostream>
using namespace std;

// base class
class A {
public:
    void function() {
        cout << "This is a function from class `A`.\n";
    }
};

// it's derived class for A but base class for C
class B: public A {
public:
    void function_2() {
        cout << "This is function from class `B`.\n";
    }
};

// derived class
class C: public B {
public:
    void function_3() {
        cout << "This is function from class `C`.\n";
    }
};

int main(void) {
    C myObj;
    myObj.function();
    myObj.function_2();
    myObj.function_3();

    return 0;
}