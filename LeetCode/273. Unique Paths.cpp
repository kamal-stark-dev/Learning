// 62. Unique Paths

#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    // move right and down
    return helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
}

int uniquePaths_Brute(int m, int n) {
    return helper(0, 0, m, n);
}

// dp
int uniquePaths_2D(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0];
}

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[j] += dp[j + 1];
        }
    }
    return dp[0];

    /* you can also do this

    vector<int> dp(m, 1);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < m; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[m - 1];

    */
}

int main(void) {
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << "\n";

    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m or n)
*/