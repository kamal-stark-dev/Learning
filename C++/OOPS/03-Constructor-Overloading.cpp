// Constructor Overloading - You can have more than one constructor in a class, but each constructor must have different number or type of parameters. So, the compiler knows which one to use when you create an object.

#include <iostream>
using namespace std;


// Constructor Overloading allows flexiblility while creating objects.
class MyCar {
public:
    string brand;
    string model;

    MyCar() {
        brand = "Not Defined";
        model = "Not Defined";
    }

    MyCar(string b, string m) {
        brand = b;
        model = m;
    }

    void show_details() {
        cout << "Car: " << brand << "\nModel: " << model << "\n";
    }
};

int main(void) {
    MyCar car1;
    MyCar car2("Mustang", "Ford - 2017");

    car1.show_details();
    car2.show_details();

    return 0;
}