// Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
using namespace std;

void solve(int i, string curr, string digits, vector<string>& ans, string char_map[]) {
    if (i >= digits.size()) {
        ans.push_back(curr);
        return;
    }

    int idx = digits[i] - '0';
    string letters = char_map[idx];

    for (int j = 0; j < letters.size(); j++) {
        curr.push_back(letters[j]);
        solve(i + 1, curr, digits, ans, char_map);
        curr.pop_back();
    }
}

vector<string> letterCombination(string digits) {
    vector<string> ans;
    if (digits.size() == 0) return ans;

    string curr;
    string char_map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(0, curr, digits, ans, char_map);
    return ans;
}

int main(void) {
    string digits = "23";
    vector<string> combinations = letterCombination(digits);

    for (string str: combinations) {
        cout << str << ", ";
    }
    cout << "\b\b \n";

    return 0;
}

/*
Time Complexity: O(4 ^ n), for each digit there are maximum 4 possibilities
Space Complexity: O(4 ^ n), recursion stack
*/