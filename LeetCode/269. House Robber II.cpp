// 213. House Robber II

#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int>& nums, int start, int end) {
    int curr = 0, prev = 0, temp = 0;
    for (int i = start; i < end; i++) {
        temp = curr;
        curr = max(curr, prev + nums[i]);
        prev = temp;
    }
    return curr;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    return max(helper(nums, 1, n), helper(nums, 0, n - 1));
}

int main(void) {
    // vector<int> nums = {2, 3, 2}; // 3
    vector<int> nums = {2, 7, 9, 3, 1}; // 11
    cout << rob(nums) << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/