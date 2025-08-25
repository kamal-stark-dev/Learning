// Permutation with Spaces - https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1

#include <iostream>
#include <vector>
using namespace std;

void helper(int i, string curr, string s, vector<string>& ans) {
    curr.push_back(s[i]);

    if (i >= s.size() - 1) {
        ans.push_back(curr);
        return;
    }

    curr.push_back(' ');
    helper(i + 1, curr, s, ans);

    curr.pop_back();
    helper(i + 1, curr, s, ans);
}

vector<string> getPermutations(string s) {
    vector<string> permutations;
    string curr;
    helper(0, curr, s, permutations);
    return permutations;
}

int main(void) {
    string s = "ABC";
    vector<string> permutationsWithSpaces = getPermutations(s);

    cout << "Permutations with Spaces are: \n";
    for (string s: permutationsWithSpaces) {
        cout << "(" << s << "), ";
    }
    cout << "\b\b \n";

    return 0;
}

/*
Time Complexity: O(n * 2 ^ (n - 1)) -> O(n * 2 ^ n)
Space Complexity: O(n * 2 ^ (n - 1)) -> (n * 2 ^ n), becuase we are storing the result + recursion stack
*/