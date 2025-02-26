#include <iostream>
using namespace std;

// decimal to binary - below appraoch is not the best one but it's simple to understand
void decimalToBinary(int num) {
    int binary = 0;
    int pow = 1;
    while (num > 0) {
        binary += pow * (num % 2);
        pow *= 10;
        num /= 2;
    }
    cout << binary << endl;
    return;
}

void binaryToDecimal(int binary) {
    int decimal = 0, pow = 1;

    while (binary > 0) {
        decimal += pow * (binary % 10);
        pow *= 2;
        binary /= 10;
    }

    cout << decimal << endl;
    return;
}

int genericBaseConvert(int number, int baseA, int baseB, char k = 'y') {
    int res = 0;
    int pow = 1;
    int original = number;

    while (number > 0) {
        res += pow * (number % baseB);
        pow *= baseA;
        number /= baseB;
    }

    if (k == 'y')
        cout << "(" << original << ")base-" << baseA << " = (" << res << ")base-" << baseB << endl;
    return res;
}

int main(void) {
    cout << "10 in binary is: ";
    decimalToBinary(10);

    cout << "The binary of 1010 is: ";
    binaryToDecimal(1010);

    for (int i = 0; i <= 10; i++) {
        cout << "binary of " << i << " is: ";
        decimalToBinary(i);
    }
    cout << endl;

    cout << "Binary <-> Decimal" << endl;
    genericBaseConvert(1010, 2, 10);
    genericBaseConvert(37, 10, 2);

    cout << "\nDecimal <-> Octal" << endl;
    genericBaseConvert(37, 10, 8);
    genericBaseConvert(37, 8, 10);

    cout << "\nBinary <-> Octal" << endl;
    genericBaseConvert(genericBaseConvert(10, 2, 10, 'n'), 10, 8);
    genericBaseConvert(genericBaseConvert(12, 8, 10, 'n'), 10, 2);


    // bonus - use of _ or ' to increase readability (literals) >> `_` can be used in c++14 and later versions
    int salary = 1'000'000;
    int color = 0xFF'00'FF;

    cout << "\nSalary: " << salary << endl << "Color: " << color << endl;

    return 0;
}