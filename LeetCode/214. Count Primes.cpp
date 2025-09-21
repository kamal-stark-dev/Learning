// 204. Count Primes [Sieve of Eratosthenes]

#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int num) { // O(n * log(n)) -> apprax., Space -> O(n)
    if (num < 2) return 0;

    int count = 0;
    vector<bool> sieve(num, true);

    for (int i = 2; i < num; i++) {
        if (sieve[i]) {
            count++;
            for (int j = i * 2; j < num; j += i) sieve[j] = false;
        }
    }
    return count;
}

int countPrimes_Optimized(int num) {
    if (num < 2) return 0;

    vector<bool> sieve(num, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i < num; i++) {
        if (sieve[i]) {
            for (int j = i * i; j < num; j += i) {
                sieve[j] = false;
            }
        }
    }

    return count(sieve.begin(), sieve.end(), true);
}

int main(void) {
    int num = 7;

    cout << "There are " << countPrimes(num) << " prime numbers less than " << num << "\n";

    return 0;
}

/*
Time Complexity: O(n * log(log(n)))
Space Complexity: O(n)
*/