// 516. Longest Palindromic Subsequence

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void dfs(int i, string substr, const string& s, int& res) {
    if (i == s.size()) {
        if (substr.size() > res && isPalindrome(substr)) {
            res = substr.size();
        }
        return;
    }

    dfs(i + 1, substr, s, res);
    dfs(i + 1, substr + s[i], s, res);
}

int longestPalindromeSubsequence_brute(string s) {
    int res = 0;
    dfs(0, "", s, res);
    return res;
}

// dynamic programming - top down (giving TLE)
int helper(int i, int j, string s, vector<vector<int>>& dp) {
    if (i < 0 || j >= s.size()) {
        return 0;
    }
    if (s[i] == s[j]) {
        int len = (i == j) ? 1 : 2;
        dp[i][j] = len + helper(i - 1, j + 1, s, dp);
    }
    else {
        dp[i][j] = max(helper(i - 1, j, s, dp), helper(i, j + 1, s, dp));
    }
    return dp[i][j];
}

int longestPalindromeSubsequence_topdown(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        helper(i, i, s, dp);
        helper(i, i + 1, s, dp);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

// using lcs (longest common subsequence) -> if we find the lcs of s and s.reverse() then that would also be the longest palindrome subsequence
int lcs(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<int> dp(n + 1, 0);

    for (int i = m - 1; i >= 0; i--) {
        int prevDiag = 0;
        for (int j = n - 1; j >= 0; j--) {
            int temp = dp[j];

            if (text1[i] == text2[j]) {
                dp[j] = 1 + prevDiag;
            }
            else {
                dp[j] = max(dp[j], dp[j + 1]);
            }
            prevDiag = temp;
        }
    }
    return dp[0];
}

int longestPalindromeSubsequence_lcs(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcs(s, rev);
}


int main(void) {
    string s = "bbbab";
    cout << longestPalindromeSubsequence_lcs(s) << "\n";

    return 0;
}

/*
Time Complexity: O(n * n)
Space Complexity: O(n)
*/