// 2220. Minimum Bit Flips to Convert Number

#include <iostream>
using namespace std;

int countSetBits(int num) {
    int count = 0;

    while (num) {
        count += num & 1;
        num >>= 1; // divide by two
    }
    return count;
}

int minBitFlips(int start, int goal) {
    int xorr = start ^ goal;
    return countSetBits(xorr);
    // return __builtin_popcount(xorr);
}

int main(void) {
    int start = 10, goal = 7;

    cout << "Minimum bit filps to convert " << start << " to " << goal << " are: " << minBitFlips(start, goal) << "\n";

    return 0;
}

/*
Time Complexity: O(log(start ^ goal)) -> O(log(n))
Space Complexity: O(1)
*/