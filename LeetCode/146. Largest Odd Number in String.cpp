// 1903. Largest Odd Number in String

#include <iostream>
using namespace std;

// my approach
string largestOddNumber(string s) {
    int n = s.size();
    int idx = -1;

    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2) {
            idx = i;
            break;
        }
    }
    return (idx == -1) ? "" : s.substr(0, idx + 1);
}

// slightly better
string largestOddNumber_littleBetter(string s) {
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2) return s.substr(0, i + 1);
    }
    return "";
}

int main(void) {
    string s = "52108";

    string odd = largestOddNumber(s);
    cout << "Largest odd number: " << odd << "\n";

    return 0;
}

/*
Time Complexity: O(n)
*/