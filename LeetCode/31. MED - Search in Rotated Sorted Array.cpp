// 33. Search in Rotated Sorted Array - https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force -> Linear Search ==> O(n)
int linearSearch_brute(vector<int> nums, int target) {
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        if (target == nums[i]) return i;
    }
    return -1;
}

// Time Complexity ==> O(log.n)
int rotatedBinarySearch(vector<int> nums, int target) {
    int size = nums.size();
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == nums[mid]) return mid;

        else if (nums[left] <= nums[mid]) { // left sorted
            if (nums[left] <= target && target <= nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        else { // right sorted
            if (nums[mid] <= target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int main(void) {

    vector<int> nums = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 2;

    cout << rotatedBinarySearch(nums, target) << endl;

    return 0;
}