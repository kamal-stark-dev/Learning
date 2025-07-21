
#include <iostream>
#include <vector>
using namespace std;

// Count number of substrings
int countSubstrings(string &s) {
    int n = s.length();
    return (n * (n + 1)) / 2 + 1; // we are adding one for empty string ("")
}

int atoi(string &s) {
    int num = 0;
    for (char c: s) {
        num = (num * 10) + (c - '0');
    }
    return num;
}

// Sum all the substrings (str -> "123")
int sumOfSubstrings_Brute(string &s) {
    int n = s.length();
    int res = 0;

    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = i; j < n; j++) {
            temp *= 10;
            temp += s[j] - '0';
            res += temp;
        }
    }
    return res;
}

// Print all the substrings
void printSubstrings(string s) {
    int n = s.length();

    cout << "[";
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            string substr = s.substr(i, len);
            cout << substr << ", ";
        }
    }
    cout << "\b\b]\n";
    return;
}

// Using DP - Time: O(n), Space: O(n)
int sumOfSubstrings_Better(string &s) {
    int n = s.length();
    vector<int> sumOfDigit(n);
    sumOfDigit[0] = s[0] - '0';
    int res = sumOfDigit[0];

    for (int i = 1; i < n; i++) {
        int currDigit = s[i] - '0';
        sumOfDigit[i] = ((i + 1) * currDigit) + (10 * sumOfDigit[i - 1]);
        res += sumOfDigit[i];
    }
    return res;
}

int main(void) {
    string s = "abcde";
    cout << "There are " << countSubstrings(s) << " substrings `" << s << "`.\n";

    s = "abcde";
    cout << "All the substrings of `" << s << "` are: \n";
    printSubstrings(s);

    string numStr = "123";
    cout << "Sum of all the substrings of `" << numStr << "` is " << sumOfSubstrings_Better(numStr) << ".\n";

    return 0;
}