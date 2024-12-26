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
    int bf = n;

    if (n < 0) {
        x = 1 / x;
        bf *= -1;
    }

    while (bf > 0) {
        if (bf % 2 == 1) res *= x;
        x *= x;
        bf /= 2;
    }

    return res;
}

int main(void) {

    double n = 2;
    int p = 30;

    cout << myPow(n, p) << endl;

    return 0;
}