// 1143. Longest Common Subsequence

#include <iostream>
#include <vector>
using namespace std;

// recursion (brute): TC: O(2 ^ (m + n)), SC: O(m + n)
int dfs(int i, int j, const string& text1, const string& text2) {
    if (i == text1.size() || j == text2.size()) {
        return 0;
    }
    if (text1[i] == text2[j]) {
        return 1 + dfs(i + 1, j + 1, text1, text2);
    }
    return max(dfs(i + 1, j, text1, text2), dfs(i, j + 1, text1, text2));
}

int longestCommonSubsequence_brute(string text1, string text2) {
    return dfs(0, 0, text1, text2);
}

// dynamic programming

// memoization (still give TLE), Tc: O(m x n), SC: O(m x n)
int dfs_2(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
    if (i == text1.size() || j == text2.size()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // calculate the lcs
    if (text1[i] == text2[j]) {
        dp[i][j] = 1 + dfs_2(i + 1, j + 1, text1, text2, dp);
    }
    else {
        dp[i][j] = max(dfs_2(i + 1, j, text1, text2, dp), dfs_2(i, j + 1, text1, text2, dp));
    }
    return dp[i][j];
}

int longestCommonSubsequence_topdown(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return dfs_2(0, 0, text1, text2, dp);
}

// tabulation, TC: O(m x n), SC: O(m x n)
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}

// 2-row DP - TC: O(m x n), SC: O(n)
int longestCommonSubsequence_2rowDP(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<int> curr(n + 1, 0), prev(n + 1, 0);

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                curr[j] = 1 + prev[j + 1];
            }
            else {
                curr[j] = max(curr[j], prev[j + 1]);
            }
            prev = curr;
        }
    }
    return prev[0];
}

// 1-row DP - TC: O(m x n), SC: O(n)
int longestCommonSubsequence_1rowDP(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<int> dp(n + 1, 0);

    for (int i = m - 1; i >= 0; i--) {
        int prevDiag = 0;
        for (int j = n - 1; j >= 0; j--) {
            int temp = dp[j]; // save old dp[i + 1][j]

            if (text1[i] == text2[j]) {
                dp[j] = 1 + prevDiag;
            }
            else {
                dp[j] = max(dp[j], dp[j + 1]);
            }
            prevDiag = temp; // shift the diagonal for next column
        }
    }
    return dp[0];
}

// it can also be done in min(m, n) space.

int main(void) {
    // string text1 = "abcde", text2 = "ace";
    string text1 = "abcba", text2 = "abcbcba";

    cout << longestCommonSubsequence_1rowDP(text1, text2) << "\n";

    return 0;
}

/*
m -> size of text1
n -> size of text2

Time Complexity: O(m x n)
Space Complexity: O(m x n) -> can do it in O(min(m, n))
*/