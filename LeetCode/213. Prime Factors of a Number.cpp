// Print Prime Factors of a Number - https://www.geeksforgeeks.org/problems/prime-factors5052/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

vector<int> findPrimeFactors_Brute(int num) { // O(n * root(n)) -> approx, Space -> O(log(n)) in worst case
    vector<int> factors;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0 && isPrime(i)) {
            factors.push_back(i);
        }
    }
    return factors;
}

vector<int> findPrimeFactors(int num) {
    vector<int> factors;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            factors.push_back(i);
            while (num % i == 0) {
                num /= i;
            }
        }
    }
    if (num != 1) factors.push_back(num);

    return factors;
}

unordered_map<int, int> findFullPrimeFactorization(int num) { // O(root(n)) -> slightly slower as it pushes multiple times
    unordered_map<int, int> factors;

    while (num % 2 == 0) { // handle 2 separately (even prime)
        factors[2]++;
        num /= 2;
    }

    // handle odd primes
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            factors[i]++;
            num /= i;
        }
    }

    if (num > 2) {
        factors[num]++;
    }

    return factors;
}

int main(void) {
    int num = 220;

    vector<int> primeFactors = findPrimeFactors(num);

    cout << "Unique Prime Factors: ";
    for (int factor: primeFactors) cout << factor << ", ";
    cout << "\b\b \n";

    unordered_map<int, int> fullPrimeFactors = findFullPrimeFactorization(num);

    cout << "Full Prime Factors: ";
    for (auto factor: fullPrimeFactors) {
        for (int i = 0; i < factor.second; i++) {
            cout << factor.first << " x ";
        }
    }
    cout << "\b\b \n";

    return 0;
}

/*
Time Complexity: O(root(n) / log(n)) -> in worst case -> O(root(n))
Space Complexity: O(log(n)) -> maximum number of distinct prime numbers (since smallest prime is 2)
*/