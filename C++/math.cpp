#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << floor(1.6) << endl
        << ceil(1.6) << endl
        << round(1.6) << endl
        << pow(3, 2) << endl;

    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    const double pi = 3.14;
    double area = pi * radius * radius; // or pi * pow(radius, 2)

    cout << "The area of the circle is: " << area << endl;

    return 0;
}