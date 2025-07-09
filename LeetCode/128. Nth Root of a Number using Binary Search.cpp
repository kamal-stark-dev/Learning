#include <iostream>
#include <cmath>
using namespace std;

int nthRoot(int num, int n) {
    if (n == 1) return num;
    int left = 1, right = num;
    int res = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long power = pow(mid, n);
        if (power <= num) {
            if (power == num) res = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return res;
}

int main(void) {
    int num = 67, n = 2;
    cout << "The nth(" << n << ") root of " << num << " is " << nthRoot(num, n) << '\n';

    num = 81, n = 4;
    cout << "The nth(" << n << ") root of " << num << " is " << nthRoot(num, n) << '\n';

    return 0;
}