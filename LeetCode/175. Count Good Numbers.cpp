// 1922. Count Good Numbers

#include <iostream>
using namespace std;

const long long BIG = 1e9 + 7;

/* Pattern
    0 - 1
    1 - 5 (x5)
    2 - 20 (x4)
    3 - 100 (x5)
    4 - 400 (x4)
    5 - 2000 (x5)
    ... so on
*/

// Will give TLE for larger numbers
long long countGoodNumbers_Brute(long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return (countGoodNumbers_Brute(n - 1) * 4) % BIG;
    else return (countGoodNumbers_Brute(n - 1) * 5) % BIG;
}

// O(log n)
long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % BIG;
        }
        base = (base * base) % BIG;
        exp /= 2;
    }
    return result;
}

// O(log digitCount)
long long countGoodNumbers(long long n) {
    long long evens = (n + 1) / 2;
    long long odds = n / 2;

    long long even_ways = power(5, evens);
    long long odd_ways = power(4, odds);

    return (even_ways * odd_ways) % BIG;
}

int main(void) {
    long long num = 50;
    cout << "Count of good numbers of length " << num << " are: " << countGoodNumbers(num) << "\n";

    return 0;
}

/*
Time Complexity: O(log n) -> n is count of digits
Space Complexity: O(1)
*/