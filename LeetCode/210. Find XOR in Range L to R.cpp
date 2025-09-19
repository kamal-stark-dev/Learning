// Find XOR from L to R

#include <iostream>
using namespace std;

int rangeXOR_Brute(int left, int right) { // O(range(left, right))
    int xorr = 0;
    for (int i = left; i <= right; i++) {
        xorr ^= i;
    }
    return xorr;
}

int XORtillN(int num) { // XOR follows this pattern when you start from 1
    if (num % 4 == 1) return 1;
    if (num % 4 == 2) return num + 1;
    if (num % 4 == 3) return 0;
    return num;
}

int rangeXOR(int left, int right) {
    return XORtillN(left - 1) ^ XORtillN(right); // [XOR(1 to (left - 1)) ^ XOR(1 to right)]
}

int main(void) {
    int left = 3, right = 5;

    cout << "(" << left << " ^ ... ^ " << right << ") = " << rangeXOR(left, right) << "\n";

    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/