// 55. Jump Game

#include <iostream>
#include <vector>
using namespace std;

// brute - TC: O(2 ^ n), SC: O(1)
bool helper(int i, vector<int>& nums) {
    if (i == nums.size() - 1) return true;
    if (nums[i] == 0) return false;

    for (int idx = 1; idx <= nums[i]; idx++) {
        if(helper(i + idx, nums)) return true;
    }
    return false;
}

bool canJump_brute(vector<int>& nums) {
    return helper(0, nums);
}

// memoization - TC: O(n ^ 2), SC: O(n)
bool helper_2(int i, vector<int>& nums, vector<int>& dp) {
    if (dp[i] != -1) return dp[i];
    if (i == nums.size() - 1) return 1;
    // if (nums[i] == 0) return 0;

    dp[i] = false;
    for (int j = 1; j <= nums[i]; j++) {
        if(helper_2(i + j, nums, dp)) {
            dp[i] = true;
            break;
        }
    }
    return dp[i];
}

bool canJump_memo(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return helper_2(0, nums, dp);
}


bool canJump(vector<int>& nums) {
    int n = nums.size();
    int idx = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        if (i + nums[i] >= idx) {
            idx = i;
        }
    }
    return idx == 0;
}

int main(void) {
    // vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums = {2, 0, 0};
    cout << (canJump_memo(nums) ? "true": "false") << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/