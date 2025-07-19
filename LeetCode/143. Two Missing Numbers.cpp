// Two Missing Numbers
// Given an array of size n-2 with unique numbers from 1 to n, find the two missing numbers.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time: O(2n), Space: O(n)
vector<int> findMissingNumbers_Brute(vector<int>& nums) {
    int n = nums.size() + 2;
    vector<int> res;
    vector<bool> present(n + 1, false);

    for (int num: nums) {
        present[num] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (present[i] == false) res.push_back(i);
    }
    return res;
}

// Time: O(n), Space: O(1)
vector<int> findMissingNumbers_Optimal(vector<int>& nums) {
    int n = nums.size() + 2;

    int actual_sum = 0, natural_sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n - 2; i++) {
        actual_sum += nums[i];
    }

    int sum = natural_sum - actual_sum;
    int avg = sum / 2;

    int left_sum = 0;
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] <= avg) left_sum += nums[i];
    }

    int intended_sum = (avg * (avg + 1)) / 2;
    int first_term = intended_sum - left_sum;
    int second_term = sum - first_term;

    return {first_term, second_term};
}

// Time: O(2n), Space: O(1)
vector<int> findMissingNumbers_Optimal_2(vector<int>& nums) {
    int n = nums.size() + 2;

    int a_xor_b = 0;
    for (int i = 1; i <= n; i++) a_xor_b ^= i;
    for (int i = 0; i < n - 2; i++) a_xor_b ^= nums[i];

    int lsb = a_xor_b & ~(a_xor_b - 1);
    int missing1 = 0, missing2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i & lsb) missing1 ^= i;
        // else missing2 ^= i;
    }
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] & lsb) missing1 ^= nums[i];
        // else missing2 ^= nums[i];
    }
    missing2 = a_xor_b ^ missing1;
    return {missing1, missing2};
}

int main(void) {
    vector<int> nums = {1, 2, 4}; // 1 to 5 is the range

    vector<int> missingNumbers = findMissingNumbers_Optimal_2(nums);
    cout << "The missing numbers are " << missingNumbers[0] << " and " << missingNumbers[1] << "\n";

    return 0;
}