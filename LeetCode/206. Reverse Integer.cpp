// 7. Reverse Integer

#include <iostream>
using namespace std;

int reverseInteger(int x) {
    int result = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;

        result = result * 10 + digit;
    }
    return result;
}

int main(void) {
    int x = -123;

    cout << "Reverse Integer: " << reverseInteger(x) << "\n";

    return 0;
}

/*
Time Complexity: O(n), n -> number of digits in number
Space Complexity: O(1)
*/