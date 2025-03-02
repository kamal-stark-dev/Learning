#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) { // you cal also use the condition -> `i < sqrt(num)`
        if (num % i == 0) return false;
    }
    return true;
}

// Brute Force Approach
int countPrimes(int n) {
    int primes = 0;
    for (int num = 2; num < n; num++) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) isPrime = false;
        }
        if (isPrime) primes++;
    }
    return primes;
}

// Sieve of Erathosthenes
int sieveOfErathosthenes(int till) {
    vector<bool> arePrimes(till + 1, true); // making a vector of boolean values setting all as primes from `0` to `n`
    int primes_count = 0;

    for (int i =  2; i < arePrimes.size(); i++) {
        if (i && isPrime(i)) primes_count++;

        for (int j = i * 2; j < arePrimes.size(); j += i) {
            arePrimes[j] = false;
        }
    }
    return primes_count;
}

int main() {
    // Prime
    int number = 13;
    string output = isPrime(number) ? " is Prime!!\n" : " is not Prime!!\n";
    cout << number << output;

    cout << "Their are " << sieveOfErathosthenes(10) << " prime numbers from 1 to 10\n";
}