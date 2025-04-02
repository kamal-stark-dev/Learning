// Factorials less than N (Recursion)
// Link - https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1

#include <bits/stdc++.h>
using namespace std;

vector<long long> factorialsTillN(int n, int num = 1, int i = 2) {
    vector<long long> factorials;

    if (num > n) return factorials;
    factorials.push_back(num);

    vector<long long> next = factorialsTillN(n, num * i, i + 1);
    factorials.insert(factorials.end(), next.begin(), next.end());

    return factorials;
}

int main(void) {
    int num = 25;

    vector<long long>  factorialNumbers = factorialsTillN(num);

    for (long long n : factorialNumbers) cout << n << " ";

    return 0;
}