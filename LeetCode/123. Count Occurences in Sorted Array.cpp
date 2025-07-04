#include <iostream>
#include <vector>
using namespace std;

int countOccurences(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int startIdx = -1, endIdx = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            if (nums[mid] == target) startIdx = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target) {
            if (nums[mid] == target) endIdx = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    if (startIdx == -1) return 0;
    return endIdx - startIdx + 1;
}

int main(void) {
    vector<int> nums = {2, 2, 3, 3, 3, 3, 4, 4, 5};
    int target = 7;

    cout << "There are " << countOccurences(nums, target) << " occurences of " << target << " in the array.\n";

    return 0;
}