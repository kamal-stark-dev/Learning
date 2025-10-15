// Prime Factorization using Sieve - https://www.geeksforgeeks.org/dsa/prime-factorization-using-sieve-olog-n-multiple-queries/

#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100001
vector<int> SPF(MAXN + 1, 0);

void calcSPF() { // O(n log log n)
    SPF[1] = 1;

    for (int i = 2; i * i <= MAXN; i++) {
        if (SPF[i] == 0) {
            SPF[i] = i;
            for (int j = i * i; j <= MAXN; j += i) {
                if (SPF[j] == 0)
                    SPF[j] = i;
            }
        }
    }

    for (int i = 2; i <= MAXN; i++) {
        if (SPF[i] == 0) SPF[i] = i; // catch any remaining primes (primes bigger than sqrt(MAXN))
    }
}

vector<int> primeFactorization(int n) { // O(log n)
    vector<int> primes;

    while (n != 1) {
        primes.push_back(SPF[n]);
        n /= SPF[n];
    }
    return primes;
}

int main(void) {
    int n = 100;
    calcSPF(); // preprocessing

    vector<int> primes = primeFactorization(n);
    for (int prime: primes) cout << prime << " ";

    cout << "\n";

    for (int i = 0; i < primes.size(); i++) {
        cout << "haha car go vroom vroom boom boom brrr...\n";
    }

    return 0;
}

/*
Preprocessing:
    Time Complexity: O(M log log M), M = MAXN
    Space Complexity: O(M), M = MAXN
Querying:
    Time Complexity: O(log n)
    Space Complexity: O(log n), to store prime factors

Final:
    Time Complexity: O(MAXN log log MAXN + log n)
    Space Complexity: O(MAXN)
*/

// hello mello my man my fellow