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

long long binaryToDecimal(string binary) {
    long long decimal = 0;
    int m = 1;
    for (int i = binary.size() - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * m;
        m *= 2;
    }
    return decimal;
}

int setBit(int num, int i) {
    return num | (1 << i); // num = 13, i = 1 ==> [1101 | 0010] -> 1111 => 15
}

int unsetBit(int num, int i) {
    return num & ~(1 << i);
}

int toggleBit(int num, int i) {
    return num ^ (1 << i);
}

int countSetBits(int num) { // O(log2 n) -> O(31)
    int count = 0;
    while (num) {
        count += num & 1; // if (num % 2) count++; (num & 1) odd check is faster
        num >>= 1; // num /= 2;
    }
    return count;

    // return __builtin_popcount(num);
}

int countSetBits_2(int num) { // O(no. of set bits) -> better than above appraoch most of the times [as no. of set bits is usually lesser than log2 n]
    int count = 0;
    while (num) {
        num = num & (num - 1); // num &= num - 1;
        count++;
    }
    return count;
}

void swapUsingBitsManipulation(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

/*
Side Note: `(low + high) >> 1` is faster than `(low + high) / 2`
*/

int main(void) {
    int num = 13; // 13 -> 1101

    // decimal to binary
    cout << "Binary of " << num << " is: " << decimalToBinary(num) << "\n";

    // checking if i-th bit is set
    cout << "The 1st bit of " << num << " from right is: " << (ithBitSet(num, 1) ? "1": "0") << "\n"; // 0
    cout << "The 2nd bit of " << num << " from right is: " << (ithBitSet(num, 2) ? "1": "0") << "\n"; // 1

    // odd / even check
    cout << num << " is " << (numIsOdd(num) ? "odd": "even") << ".\n";

    // power of 2
    cout << num << " is power of 2: " << (isPowerOf2(num) ? "True": "False") << "\n";
    cout << 16 << " is power of 2: " << (isPowerOf2(16) ? "True": "False") << "\n";
    cout << 0 << " is power of 2: " << (isPowerOf2(0) ? "True": "False") << "\n";

    // binary to decimal (unsigned)
    cout << "The decimal of `1101` is: " << binaryToDecimal("1101") << "\n";
    cout << "The decimal of `0` is: " << binaryToDecimal("0") << "\n";
    cout << "The decimal of `1000` is: " << binaryToDecimal("1000") << "\n";

    // setting i-th bit from right to 1
    cout << num << " after setting 1st bit from the right is: " << setBit(num, 1) << "\n";
    cout << num << " after setting 2nd bit from the right is: " << setBit(num, 2) << "\n";

    // setting i-th bit from right to 0
    cout << num << " after setting 2nd bit from the right is: " << unsetBit(num, 2) << "\n";
    cout << num << " after setting 3rd bit from the right is: " << unsetBit(num, 3) << "\n";

    // toggling i-th bit from right
    cout << num << " after toggling 1st bit from the right is: " << toggleBit(num, 1) << "\n";
    cout << num << " after toggling 2nd bit from the right is: " << toggleBit(num, 2) << "\n";

    // count set bits
    cout << "There are " << countSetBits(num) << " set bits in " << num << ".\n";
    cout << "There are " << countSetBits_2(64) << " set bits in " << 64 << ".\n";

    int num1 = 10, num2 = 20;
    cout << "Before swapping num1: " << num1 << " and num2: " << num2 << "\n";
    swapUsingBitsManipulation(num1, num2);
    cout << "After swapping num1: " << num1 << " and num2: " << num2 << "\n";

    return 0;
}