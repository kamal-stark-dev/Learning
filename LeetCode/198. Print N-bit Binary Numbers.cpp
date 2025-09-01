// Print N-bit binary numbers having more 1s than 0s - https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

#include <iostream>
using namespace std;

void printBinaries(int n, int counter = 0, string s = "") {
    if (s.size() == n) {
        cout << s << "\n";
        return;
    }

    printBinaries(n, counter + 1, s + '1');

    if (counter > 0) {
        printBinaries(n, counter - 1, s + '0');
    }
}

int main(void) {
    int n = 3;

    printBinaries(n);

    return 0;
}

/*
Time Complexity: O(n * K), K -> no. of valid binary strings (K = 2 ^ n in worst case), times `n` because for each valid string we are making `n` calls.

Space Complexity: O(n), maximum recursion depth in `n` and also the maximum size of string `s`. (It would be O(n * K) if we were storing the result).
*/