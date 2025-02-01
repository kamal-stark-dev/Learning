// 18. 4Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using the 2 pointers approach
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int size = nums.size();

    if (size < 4) return {};

    for (int i = 0; i < size; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < size; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1, right = size - 1;
            long long sum = 0;
            while (left < right) {
                sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];

                if (sum < target) left++;
                else if (sum > target) right--;
                else {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++; right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
    }
    return ans;
}

int main(void) {
    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<int> nums = {1, -2, -5, -4, -3, 3, 3, 5};
    int target = -11;

    vector<vector<int>> res = fourSum(nums, target);

    cout << "4 Sum Unique Quadruplets:\n";
    for (auto row: res) {
        cout << "{";
        for (int n: row) {
            cout << n << ", ";
        }
        cout << "\b\b}\n";
    }

    return 0;
}

/*
Time Complexity: O(n.logn + n ^ 3)
Space Complexity: O(uniqueQuadruplets)
*/