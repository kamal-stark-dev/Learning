// 22. Generate Parentheses

#include <iostream>
#include <vector>
using namespace std;

void recursive(vector<string>& ans, string& s, int counter, int total, int n) {
    if (total == n && counter == 0) {
        ans.push_back(s);
        return;
    }

    if (total != n) {
        s += "(";
        recursive(ans, s, counter + 1, total + 1, n);
        s.pop_back();
    }

    if (counter > 0) {
        s += ")";
        recursive(ans, s, counter - 1, total, n);
        s.pop_back();
    }
}

vector<string> generateParentheses(int n) {
    vector<string> ans;
    int c = 0, t = 0;
    string s = "";
    recursive(ans, s, c, t, n);
    return ans;
}

int main(void) {
    int n = 3;

    vector<string> parentheses = generateParentheses(n);
    cout << "All valid parentheses of size " << n << " are:\n[";
    for (string s: parentheses) cout << s << ", ";
    cout << "\b\b]\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n), due to recursion stack
*/