// 779. K-th Symbol in Grammar

#include <iostream>
#include <cmath>
using namespace std;

// Brute - has O(2 * n) time complexity
int kthSymbol(int n, int k, string language = "0") {
    if (n == 1) {
        return language[k - 1] - '0'; // k - 1 becase it's one-indexed
    }

    string newLanguage = "";
    for (char c: language) {
        if (c == '0') newLanguage += "01";
        else newLanguage += "10";
    }
    return kthSymbol(n - 1, k, newLanguage); // making it an integer
}

// Optimal - O(n) time complexity
int kthSymbol_Optimal(int n, int k) {
    int curr = 0;
    int left = 1, right = pow(2, n - 1);

    for (int _ = 0; _ < n - 1; _++) { // we loop till (n - 1) because setting `curr = 0` is covering the first row
        int mid = left + (right - left) / 2;

        if (k <= mid) right = mid;
        else {
            left = mid + 1;
            curr = 1 - curr;
        }
    }

    return curr;
}

int main(void) {
    int n = 2, k = 1;
    cout << "k-th(" << k << ") symbol in grammer for row number " << n << " is " << kthSymbol_Optimal(n, k) << "\n";

    return 0;
}

/*
Brute:
    Time Complexity: O(2 ^ n)
    Space Complexity: O(2 ^ n), as nth level string size => [2 ^ n]

Optimal:
    Time Complexity: O(n), basically applying a smart binary search over the tree of the language
    Space Complexity: O(1)
*/