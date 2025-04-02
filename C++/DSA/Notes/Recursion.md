# Recursion

Recursion is where a **function calls itself** to solve smaller instances of a problem.

> Recursion is often used for tasks like traversing data structures, solving mathematical problems, or implementing algorithms.

### Basic Recursion Programs (Beginners)

You can look at these little programs to practice `recursion`.

```cpp
#include <bits/stdc++.h>
using namespace std;

void printNums_Ascending(int i, int n) {
    if (i > n) return;
    cout << i << " ";
    printNums_Ascending(i + 1, n);
}

void printNums_Descending(int n) {
    if (n == 0) return;

    cout << n << " ";
    printNums_Descending(n - 1);
}

void printNTimes(string s, int n) {
    if (n == 0) return;
    cout << s << " ";
    printNTimes(s, n - 1);
}

void printNumsAscending_Backtracking(int i, int n) {
    if (i < 1) return;
    printNumsAscending_Backtracking(i - 1, n);
    cout << i << " "; // executed when the above func is completed
}

void printNumsDescending_Backtracking(int i, int n) {
    if (i > n) return;
    printNumsDescending_Backtracking(i + 1, n);
    cout << i << " ";
}

void printSumN(int i, int sum) {
    if (i < 1) {
        cout << sum << endl;
        return;
    }
    printSumN(i - 1, sum + i);
}

int getSumN(int n) {
    if (n == 0) return 0;
    return n + getSumN(n - 1);
}

int getFactorial(int n) {
    if (n == 0) return 1;
    return n * getFactorial(n - 1);
}

void reverseArray(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    swap(arr[left], arr[right]);
    reverseArray(arr, left + 1, right - 1);
}

void reverseArray_singlePointer(vector<int>& arr, int i = 0) {
    int n = arr.size();
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    reverseArray_singlePointer(arr, i + 1);
}

bool isPalindrome(string s, int i = 0) {
    int n = s.length();
    if (i >= n / 2) return true;
    if (s[i] != s[n - i - 1]) return false;
    return isPalindrome(s, i + 1);
}

int nthFibonacci(int n) { // multiple recursion calls
    // if (n == 0 || n == 1) return n;
    // int last = nthFibonacci(n - 1);
    // int slast = nthFibonacci(n - 2);
    // return last + slast;v
    if (n <= 1) return n;
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

int main(void) {
    cout << nthFibonacci(4) << endl;

    return 0;
}
```

---

### Factorials Less than or Equal to `N`:

I found this problem quite good for recursion practice - [Factorials Less than or Equal to n](https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1)

```cpp
vector<long long> factorialNumbers(long long n, long long num = 1, long long count = 2) {
    vector<long long> ans;

    if (num > n) return ans;

    ans.push_back(num);

    vector<long long> next = factorialNumbers(n, num * count, count + 1);

    ans.insert(ans.end(), next.begin(), next.end());

    return ans;
}
```

To be continued...
