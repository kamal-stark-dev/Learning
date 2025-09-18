// Bit Manipulation Basics

#include <iostream>
using namespace std;

bool ithBitSet(int num, int i) {
    return num & (1 << i);
}

string reverse(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
    return s;
}

string decimalToBinary(int num) {
    string binary;

    while (num) {
        bool bit = num % 2;
        num /= 2;

        if (bit) binary += "1";
        else binary += "0";
    }
    binary = reverse(binary);
    return binary;
}

bool numIsOdd(int num) {
    return num & 1;
    // return num % 2;
}

bool isPowerOf2(int num) {
    if (num <= 0) return false;
    // remember the outer parenthesis to handle operator precedence
    return (num & (num - 1)) == 0; // 8 -> 1000, 8 - 1 => 7 -> 0111 ==> 8 & 7 => 0 (True)
}



int main(void) {
    int num = 13; // 13 -> 1101

    cout << "Binary of " << num << " is: " << decimalToBinary(num) << "\n";

    cout << "The 1st bit of " << num << " from right is: " << (ithBitSet(num, 1) ? "1": "0") << "\n"; // 0
    cout << "The 2nd bit of " << num << " from right is: " << (ithBitSet(num, 2) ? "1": "0") << "\n"; // 1

    cout << num << " is " << (numIsOdd(num) ? "odd": "even") << ".\n";

    cout << num << " is power of 2: " << (isPowerOf2(num) ? "True": "False") << "\n";
    cout << 16 << " is power of 2: " << (isPowerOf2(16) ? "True": "False") << "\n";
    cout << 0 << " is power of 2: " << (isPowerOf2(0) ? "True": "False") << "\n";

    return 0;
}