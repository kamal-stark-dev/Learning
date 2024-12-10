#include <iostream>

using namespace std;

/*
System       -   Base      -  Digits          -  Example
Decimal      -   base 10   -  (0 - 9)         -  255
Binary       -   base 2    -  (0, 1)          -  11111111
Hexadecimal  -   base 16   -  (0 - 9, A - F)  -  ff
*/

int main() {
    int decimal = 255;
    int binary = 0b11111111;
    int hexadecimal = 0xff;

    cout << decimal << endl
         << binary << endl
         << hexadecimal << endl;

    return 0;
}