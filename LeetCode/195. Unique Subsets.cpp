// Unique Strings

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generate(int index, string& s, string& curr, vector<string>& ans) {
    ans.push_back(curr);

    for (int i = index; i < s.size(); ++i) {
        if (i > index && s[i] == s[i - 1]) continue;

        curr.push_back(s[i]);
        generate(i + 1, s, curr, ans);
        curr.pop_back();
    }
}

vector<string> generateUniqueSubsets(string s) {
    sort(s.begin(), s.end()); // Sort to handle duplicates
    vector<string> ans;
    string curr;
    generate(0, s, curr, ans);
    return ans;
}

int main() {
    string s = "aab";
    vector<string> uniqueSubsets = generateUniqueSubsets(s);

    cout << "Unique subsets of `" << s << "` are -> ";
    for (string subset : uniqueSubsets) {
        if (subset.empty()) cout << "\"\", ";
        else cout << subset << ", ";
    }
    cout << "\b\b \n";

    return 0;
}

/*
Time Complexity: O(2 ^ n)
Space Complexity: O(n * 2 ^ n), for storing subsets and recursion stack.
*/