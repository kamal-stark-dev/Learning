// 300. Longest Increasing Subsequence

#include <iostream>
#include <vector>
using namespace std;

// brute - recursion
// TC: O(2 ^ n), SC: O(n) -> TLE
int dfs(int i, int j, const vector<int>& nums) {
    if (i == nums.size()) return 0;

    // not-include
    int res = dfs(i + 1, j, nums);

    // include
    if (j == -1 || nums[j] < nums[i]) {
        // if we include i, new_i = i + 1, new_j = i
        res = max(res, 1 + dfs(i + 1, i, nums));
    }

    return res;
}

int lengthOfLIS_Brute(vector<int>& nums) {
    return dfs(0, -1, nums);
}

// Dynamic Programming - Bottom Up
// TC: O(n ^ 2), SC: O(n)
int lengthOfLIS_DP(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int res = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] < nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        res = max(res, dp[i]); // find the max dp[i]
    }
    return res;
}

// minimum possible tail of increasing subsequence
// TC: O(n logn), SC: O(n) -> res
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;

    for (int n: nums) {
        if (res.empty() || res.back() < n) {
            res.push_back(n);
        }
        else {
            int idx = lower_bound(res.begin(), res.end(), n) - res.begin(); // logn
            res[idx] = n;
        }
    }
    return res.size();
}

int main(void) {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Longest Increasing Subsequence Length: " << lengthOfLIS(nums) << "\n";

    return 0;
}

/*
Time Complexity: O(n logn)
Space Complexity: O(n)
*/