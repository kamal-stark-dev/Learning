// 784. Letter Case Permutation

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void helper(int i, string curr, string s, vector<string>& ans) {
    if (i >= s.size()) {
        ans.push_back(curr);
        return;
    }

    if (s[i] >= '0' && s[i] <= '9') {
        curr.push_back(s[i]);
        helper(i + 1, curr, s, ans);
    }
    else {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= 'A';
            s[i] += 'a';
        }
        curr.push_back(tolower(s[i]));
        helper(i + 1, curr, s, ans);

        curr.pop_back();
        curr.push_back(toupper(s[i]));
        helper(i + 1, curr, s, ans);
    }
}

void helper_2(int i, string curr, string s, vector<string>& ans) {
    if (i >= s.size()) {
        ans.push_back(curr);
        return;
    }

    curr.push_back(s[i]);
    helper_2(i + 1, curr, s, ans);
    curr.pop_back();

    if (isalpha(s[i])) {
        char c = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
        curr.push_back(c);
        helper_2(i + 1, curr, s, ans);
        curr.pop_back();
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> permutations;
    string curr;
    helper_2(0, curr, s, permutations);
    return permutations;
}

int main(void) {
    string s = "a1b2";

    vector<string> permutations = letterCasePermutation(s);
    cout << "Letter Case Permutations are: \n";
    for (string s: permutations) {
        cout << "(" << s << "), ";
    }
    cout << "\b\b \n";

    return 0;
}

/*
n -> length of string, k -> length of alphabets
Time Complexity: O(n * 2 ^ k)
Space Complexity: O(n * 2 ^ k)

Example: "a1b2", n = 4 & k = 2 -> 4 * (2 ^ 2) -> 4 * 4 -> 16 steps
*/