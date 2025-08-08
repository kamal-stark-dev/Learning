// Methods - Functions that belong to a class, they can be defined inside or outside the class.

#include <iostream>
using namespace std;

class MyClass {
public:
    void method1() {
        cout << "Method 1 was called.\n";
    }

    void method2(int num); // method declaration
};

// method definition outside the class
void MyClass::method2(int num) {
    cout << "Method 2 -> " << num << " was passed as argument.\n";
}

int main(void) {
    MyClass myObj;
    myObj.method1();
    myObj.method2(10);

    return 0;
}