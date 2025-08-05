// Subsequences with the Sum K

#include <iostream>
#include <vector>
using namespace std;

void subsequencesWithSumK(vector<int>& nums, int k, int i, vector<int>& curr) {
    // if array only containes +ves then you can exit if k becomes negative at any point
    if (i == nums.size()) {
        if (k == 0) {
            for (int num: curr) cout << num << " ";
            cout << '\n';
        }
        return;
    }

    // include
    curr.push_back(nums[i]);
    subsequencesWithSumK(nums, k - nums[i], i + 1, curr);

    // not-include
    curr.pop_back();
    subsequencesWithSumK(nums, k, i + 1, curr);
}

int countSubsequencesWithSumK(vector<int>& nums, int k, int i, vector<int>& curr) {
    if (i == nums.size()) {
        if (k == 0)return 1;
        return 0;
    }

    // include
    curr.push_back(nums[i]);
    int left = countSubsequencesWithSumK(nums, k - nums[i], i + 1, curr);

    // not-include
    curr.pop_back();
    int right = countSubsequencesWithSumK(nums, k, i + 1, curr);

    return left + right;
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 2};
    int k = 8;

    vector<int> curr;
    subsequencesWithSumK(nums, k, 0, curr);

    curr = {};
    cout << "The count of subsequences with sum " << k << " is " << countSubsequencesWithSumK(nums, k, 0, curr);

    return 0;
}

/*
Time Complexity: O(2 ^ n), as we need to check for each subset
Space Complexity: O(2 ^ m), recursion stack
*/