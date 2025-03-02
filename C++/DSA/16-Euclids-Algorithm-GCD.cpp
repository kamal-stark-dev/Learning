#include <iostream>
using namespace std;

// Time Complexity: O(min(a, b))
int gcdBrute(int a, int b) {
    // base cases
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    int min_val = min(a, b);
    int gcd = 1;
    for (int i = 2; i <= min_val; i++) {
        if (a % i == 0 && b % i == 0) gcd = i;
    }
    return gcd;
}

// Optimized Approach
int gcdOptimized(int a, int b) {
    // recursive approach
    // if (a == b) return a;
    // else if (a > b) return gcdEuclids(a - b, b);
    // else return gcdEuclids(a, b - a);
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}
// in here you might need to subtract b from a if a >>> b -> and division will do the same job faster

// Euclid's Algorithm
int gcdEuclids(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    if (a == 0) return b;
    else return a;
    /*
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = reminder;
    }
    return a;
    */
}

// Recursive approach for Euclid's
int gcdEuclidsRecursive(int a, int b) {
    if (b == 0) return a;
    gcdEuclidsRecursive(b, a % b);
}

int lcm(int a, int b) {
    /*
    a * b = lcm(a, b) * gcd(a , b)
    */
    return (a * b) / gcdEuclids(a, b);
}

int main() {

    // GCD - Greatest Common Divisor
    cout << "GCD of 20 and 28: " << gcdBrute(20, 28) << endl;
    cout << "GCD of 20 and 28: " << gcdOptimized(6, 12) << endl;
    cout << "GCD of 20 and 28: " << gcdEuclids(0, 56) << endl;
    cout << "GCD of 20 and 28: " << gcdEuclidsRecursive(12, 36) << endl;

    // LCM - Least Common Multiple
    cout << "LCM of 20 and 28: " << lcm(20, 28) << endl;

    return 0;
}

/*
Time Complexity Brute: O(min(a, b))
Time Complexity Euclids: O(log(min(a, b))) --> significantly faster
*/