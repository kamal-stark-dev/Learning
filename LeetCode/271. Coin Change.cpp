// 322. Coin Change

#include <iostream>
#include <vector>
using namespace std;

// Brute - TC: O(n ^ (amount / m)), where m -> min(coins)
void dfs(int amount, int count, int& ans, vector<int>& coins) {
    if (amount == 0) {
        ans = min(ans, count);
        return;
    }
    if (amount < 0) return;

    int n = coins.size();
    for (int i = 0; i < n; i++) {
        dfs(amount - coins[i], count + 1, ans, coins);
    }
}

int coinChange_brute(vector<int>& coins, int amount) {
    int ans = 100001;
    dfs(amount, 0, ans, coins);
    return ans;
}

// memoization
int dfs_m(int amount, vector<int>& dp, const vector<int>& coins) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;
    if (dp[amount] != -1) return dp[amount];

    int res = INT_MAX;
    for (int coin : coins) {
        int sub = dfs_m(amount - coin, dp, coins);
        if (sub != INT_MAX) {
            res = min(res, 1 + sub);
        }
    }

    return dp[amount] = res;
}

int coinChange_m(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    int res = dfs_m(amount, dp, coins);
    return (res == INT_MAX) ? -1 : res;
}


// tabulation
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int curr = 1; curr < amount + 1; curr++) {
        for (int coin: coins) {
            if (curr - coin >= 0) {
                dp[curr] = min(dp[curr], 1 + dp[curr - coin]);
            }
        }
    }

    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main(void) {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount) << "\n";

    return 0;
}

/*
n -> length of coins
a -> amount

Time Complexity: O(a * n)
Space Complexity: O(a)
*/