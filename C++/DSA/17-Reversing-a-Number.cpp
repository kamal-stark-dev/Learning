#include <iostream>
using namespace std;

int reverseNum(int num) {
    int rev = 0;
    int power = 10;

    while (num != 0) {
        // it is asked that if the num goes beyond the integer range then return 0
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;
        rev = (rev * power) + (num % 10);
        num /= 10;
    }
    return rev;
}

string isPalindromeNum(int num) {
    if (num < 0) return "False";
    return num == reverseNum(num) ? "True" : "False";
}

int main(void) {
    int num = -4537;
    cout << "Reverse number of " << num << " is: " << reverseNum(num) << endl;

    num = 121;
    cout << "isPalindrome(" << num << "): " << isPalindromeNum(num) << endl;

    return 0;
}

// Modulo Arithmetics -> used very large numbers
/*
Properties -
1. (x + y) % m = (x % m) + (y % m)
2. (x - y) % m = (x % m) - (y % m)
3. (x . y) % m = (x % m) . (y % m)
4. (((x % m) % m) % m) ==> (x % m)
*/