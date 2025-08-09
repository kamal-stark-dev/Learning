// Access Specifiers - used to control how the members (attributes and methods) of a class can be accessed. They help protect data and organize code so that only the right parts can see or change the data.

#include <iostream>
using namespace std;

/*
There are 3 types of access specifiers -
    1. Public
    2. Private (default)
    3. Protected
*/

class MyClass {
public:
    // the members here can be accessed and modified from outside the class.
    int a, b;
    void publicFunction() {
        cout << "This is a public function.\n";
    }
private:
    // members cannot be accessed (or viewed) from outside the class. By default all members are private.
    string secret;
protected:
    // members cannot be accessed from outside the class, but they can be accessed in inherited* (children) class. (We will learn about *Inheritance* soon)
    float inherited;
};

// Note: It's possible to access private members of a class using a public method inside the same class.

int main(void) {
    MyClass myObj;

    myObj.a = 10;
    myObj.b = 20;
    // myObj.secret = "password"; -> will raise error
    // myObj.inherited = 3.14; -> will also raise error

    cout << myObj.a << ", " << myObj.b << "\n";

    return 0;
}