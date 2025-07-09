// Finding Sqrt of a number using Binary Search

#include <iostream>
using namespace std;

int floorSqrt(int n) {
    int left = 1, right = n;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) left = mid + 1;
        else right = mid - 1;
    }
    return right;
    // return sqrt(n);
}

int main(void) {
    int n = 28;
    cout << floorSqrt(n) << " is floor square root of " << n << '\n';

    return 0;
}