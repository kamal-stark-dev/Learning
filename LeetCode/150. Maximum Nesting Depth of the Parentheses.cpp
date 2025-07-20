// 1614. Maximum Nesting Depth of the Parentheses

#include <iostream>
using namespace std;

int maxDepth(string s) {
    int n = s.length();
    int depth = 0, max_depth = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            depth++;
            max_depth = max(max_depth, depth);
        }
        else if (s[i] == ')') depth--;
    }
    return max_depth;
}

int main(void) {
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "The maximum depth of given expression is " << maxDepth(s) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
*/