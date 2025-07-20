// 8. String to Integer (atoi)

#include <iostream>
#include <vector>
using namespace std;

int myatoi(string s) {
    int i = 0, n = s.length();
    while (i < n && s[i] == ' ') i++;

    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    long long res = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') { // while there is a digit
        res = (res * 10) + (s[i] - '0');
        if (sign * res < INT_MIN) return INT_MIN;
        if (sign * res > INT_MAX) return INT_MAX;
        i++;
    }
    return res * sign;
}

int main(void) {
    vector<string> cases = {"42", "  -49", "123abc456", "0-1", "words 1234", "-91283472332"};

    for (string test_case: cases) {
        cout << myatoi(test_case) << " ";
    }
    cout << '\n';

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/