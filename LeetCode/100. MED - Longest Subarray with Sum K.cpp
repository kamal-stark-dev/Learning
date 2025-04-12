// Longest Subarray with Sum K - GFG

#include <bits/stdc++.h>
using namespace std;

int longestSubarray_brute(vector<int> nums, int k) {
    int n = nums.size();

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int longestSubarray_optimal(vector<int> nums, int k) {
    map<int, int> m; // sum, index

        int n = nums.size();
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }
            int rem = sum - k;
            if (m.find(rem) != m.end()) {
                maxLen = max(maxLen, i - m[rem]);
            }
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }
        return maxLen;
}

// if you have an array of non-negative elements then the below approach is the optimal one
int longestSubarray_optimal_nonNegatives(vector<int> nums, int k) {
    int n = nums.size();

    int sum = nums[0]; // remember to do this
    int left = 0, right = 0;
    int maxLen = 0;
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= nums[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n) {
            sum += nums[right];
        }
    }
    return maxLen;
}

int main(void) {
    // vector<int> nums = {10, 5, 2, 7, 1, -10};
    // int k = 15;

    vector<int> nums = {2, 3, 5, 1, 9};
    int k = 10;

    // cout << "The longest subarray size that sums up to " << k << " is: " << longestSubarray_brute(nums, k) << endl;
    cout << "The longest subarray size that sums up to " << k << " is: " << longestSubarray_optimal(nums, k) << endl;
    // cout << "The longest subarray size that sums up to " << k << " is: " << longestSubarray_optimal_nonNegatives(nums, k) << endl;

    return 0;
}

/*
Time Complexity:
    Brute: O(n * n)
    Optimal: O(n logn) -> map | O(n * 1) -> "unordered_map" but if `collision` occurs then it'll be O(n * n)
    Optimal Non-Negatives: O(2 * n) ==> O(n) -> as `left` and `right` may go to `n` in worst case

Space Complexity:
    Brute: O(1)
    Optimal: O(n) -> map
    Optimal Non-Negatives: O(1)
*/