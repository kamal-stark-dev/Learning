// 29. Divide Two Integers

#include <iostream>
using namespace std;

// Bit Manipulation
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    int sign = ( (dividend < 0) ^ (divisor < 0) ) ? -1 : 1;

    long long absDividend = llabs((long long) dividend), absDivisor = llabs((long long) divisor);
    long long quotient = 0;

    while (absDivisor <= absDividend) {
        long long currDivisor = absDivisor;
        long long multiple = 1;

        while ((currDivisor << 1) <= absDividend) {
            currDivisor <<= 1;
            multiple <<= 1;
        }
        absDividend -= currDivisor;
        quotient += multiple;
    }
    return sign * quotient;
}

int main(void) {
    int dividend = 7, divisor = -3;

    if (divisor == 0) {
        cerr << "Divisor can't be zero.\n";
        return -1;
    }

    cout << dividend << " / " << divisor << " = " << divide(dividend, divisor) << "\n";

    return 0;
}

/*
Time Complexity: O(log(Dividend))
Space Complexity: O(1)
*/