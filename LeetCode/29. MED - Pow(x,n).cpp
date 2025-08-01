// 50. Pow(x, n)

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == -1 && n % 2 == 0) return 1;
    if (x == -1 && n % 2 != 0) return -1;

    double res = 1;

    if (n < 0) {
        x = 1 / x;
        n *= -1;
    }

    while (n > 0) {
        if (n % 2 == 1) res *= x;
        x *= x;
        n /= 2;
    }

    return res;
}

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