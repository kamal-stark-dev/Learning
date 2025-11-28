// 167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> twoSum(vector<int> nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum == target) {
            return {i + 1, j + 1}; // 1-indexed
        }
        else if (sum > target) j--;
        else i++;
    }
    return {-1, -1};
}

int main(void) {
    // given: nums is sorted
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // given: you may not use the same element twice and it has exactly one solution
    pair<int, int> ans = twoSum(nums, target);
    cout << "Pairs are at indices: " << ans.first << " and " << ans.second << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/