// Constructor - It's a special method that is automatically called when an object of a class is created.

#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() { // Note: A constructor doesn't have any return type.
        cout << "Object Created.\n";
    }
};

class MyClass_2 {
public:
    string name;
    int age;

    MyClass_2(string name_, int age_) {
        name = name_;
        age = age_;
    }
};

class MyClass_3 {
public:
    int x, y;

    MyClass_3(int num1, int num2);
};

MyClass_3::MyClass_3(int num1, int num2) {
    x = num1;
    y = num2;
}

int main(void) {
    MyClass myObj; // creating the object will automatically invoke the constructor

    MyClass_2 o1("Jake", 20);
    MyClass_2 o2("Hardy", 21);

    cout << o1.name << " is " << o1.age << " years old.\n";
    cout << o2.name << " is " << o2.age << " years old.\n";

    MyClass_3 point(10, -5);
    cout << "Point: " << point.x << ", " << point.y << "\n";

    return 0;
}

/*
Constructor Rules:
    1. The constructor has the same name as the class-name.
    2. It has no return type (not even void).
    3. It's usually declared public.
    4. It's automatically called when an object is created.
    5. It can be defined inside or outside the class.
    6. A single class can have multiple constructors (but with different signatures).

-> Constructor can also take parameters (just like regular functions), which can be useful for setting initial values for attributes in the class.
*/