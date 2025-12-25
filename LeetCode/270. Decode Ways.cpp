// 91. Decode Ways

#include <iostream>
#include <vector>
using namespace std;

// recursion
int dfs_1(int i, string s) { // TC: O(n ^ 2), SC: O(n)
    int n = s.size();

    if (i == n) return 1;
    if (s[i] == '0') return 0;

    int res = dfs_1(i + 1, s);

    if (i + 1 < n && (s[i] == '1' || (s[i] == 2 && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
        res += dfs_1(i + 2, s);
    }
    return res;
}

int numDecodings_recursion(string s) {
    return dfs_1(0, s);
}

// top-down memoization
int dfs_2(int i, string s, vector<int>& dp) { // TC: O(n), SC: O(n)
    int n = s.size();

    if (dp[i] != -1) return dp[i];
    if (s[i] == '0') return 0;

    int res = dfs_2(i + 1, s, dp);
    if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
        res += dfs_2(i + 2, s, dp);
    }
    dp[i] = res;
    return res;
}

int numDecodings_memoization(string s) {
    int n = s.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 1;
    return dfs_2(0, s, dp);
}

// bottom-up tabulation
int numDecodings_tabulation(string s) { // TC: O(n), SC: O(n)
    int n = s.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        // single digit
        if (s[i] == '0') {
            dp[i] = 0;
        }
        else {
            dp[i] = dp[i + 1];
        }

        // double digits
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
            dp[i] += dp[i + 2];
        }
    }
    return dp[0];
}

// bottom-up optimal
int numDecodings(string s) {
    int n = s.size();
    int one = 1, two = 0; // dp[n] = 1, dp[n + 1] = 0 (dummy)

    for (int i = n- 1; i >= 0; i--) {
        int curr = 0;
        if (s[i] != '0') {
            curr = one;
        }
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
            curr += two;
        }
        two = one;
        one = curr;
    }
    return one;
}

int main(void) {
    string s = "11106";
    cout << numDecodings(s) << " ways to decode.\n";

    return 0;
}

/*
Time Complexity: O()
Space Complexity: O()
*/