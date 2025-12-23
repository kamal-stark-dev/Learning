// 70. Climbing Stairs

#include <iostream>
#include <vector>
using namespace std;

// Recursion
int helper(int n, int i) { // TC: O(2 ^ n)
    if (i >= n) return i == n;
    return helper(n, i + 1) + helper(n, i + 2);
}

int climbStairs_brute(int n) {
    return helper(n, 0);
}

// Memoization - Top-Down
int dfs(int n, int i, vector<int>& cache) {
    if (i >= n) return i == n;
    if (cache[i] != -1) return cache[i];
    return cache[i] = dfs(n, i + 1, cache) + dfs(n, i + 2, cache);
}

int climbStairs_TopDown(int n) { // Memoization, TC: O(n), SC: O(n)
    vector<int> cache(n, -1);
    return dfs(n, 0, cache);
}

// Tabulation - Bottom-Up
int climbStairs_BottomUp(int n) { // TC: O(n), SC: O(n)
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int climbStairs_BottomUp_Optimized(int n) { // TC: O(n), SC: O(1)
    int one = 1, two = 1, temp = -1;
    for (int i = 0; i < n - 1; i++) {
        temp = one;
        one = one + two;
        two = temp;
    }
    return one;
}

int main(void) {
    int n = 3;
    cout << "There are " << climbStairs_BottomUp(n) << " ways to climb to the top.\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/