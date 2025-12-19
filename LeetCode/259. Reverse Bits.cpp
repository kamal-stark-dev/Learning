// 190. Reverse Bits

#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32; i++) {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }
    return rev;
}

uint32_t reverseBits_2(uint32_t n) {
    // using the divide and conquer approach - TC: O(log n) = O(log 32) -> O(5) -> O(1)

    // n = ((n & 11111111111111110000000000000000) >> 16) | ((n & 00000000000000001111111111111111) << 16);
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);

    // n = ((n & 11111111000000001111111100000000) >> 8) | ((n & 00000000111111110000000011111111) << 8);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);

    // n = ((n & 11110000111100001111000011110000) >> 4) | ((n & 00001111000011110000111100001111) << 4);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);

    // n = ((n & 11001100110011001100110011001100) >> 2) | ((n & 00110011001100110011001100110011) << 2);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);

    // n = ((n & 10101010101010101010101010101010) >> 1) | ((n & 01010101010101010101010101010101) << 1);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

    return n;
}

int main(void) {
    uint32_t n = 43261596;
    cout << "Reverse Bits: `" << reverseBits_2(n) << "`.\n";

    return 0;
}

/*
Time Complexity: O(32) in first approach, O(5) in second approach (divide and conquer)
Space Complexity: O(1)
*/