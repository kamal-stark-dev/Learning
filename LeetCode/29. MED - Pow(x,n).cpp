// 50. Pow(x, n)

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    // base cases
    if (n == 0) return 1;
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == -1 && n % 2 == 0) return 1;
    if (x == -1 && n % 2 != 0) return -1;

    double res = 1;

    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    while (n > 0) {
        if (n % 2 == 1) res *= x;
        x *= x;
        n /= 2;
    }

    return res;
}

/*
3 ^ 9 -> x = 3, n = 9
-> 3 * 3 ^ 8 -> 3 * (3 ^ 2) ^ 8/2 -> 3 * (9 ^ 4) -> 3 * (9 ^ 2) ^ 4/2 -> 3 * (81 ^ 2) -> 3 * 81 * 81 -> 19,683
*/

int main(void) {

    double n = 2;
    int p = -2;

    cout << myPow(n, p) << endl;

    return 0;
}

/*
Time Complexity: O(log n), n is the power
Space Complexity: O(1)
*/