// 540. Single Element in a Sorted Array - https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

// logarithmic time complexity
int singleElement(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[size - 1] != nums[size - 2]) return nums[(size - 1)];

    int left = 1, right = nums.size() - 2;

    while (left <= right) {
        int  mid = left + (right - left) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
        else if (mid % 2 == 0) {
            if  (nums[mid] == nums[mid - 1]) right = mid - 1;
            else left = mid + 1;
        }
        else {
            if (nums [mid] == nums[mid - 1]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};

    cout  << "The single element is: " << singleElement(nums) << endl;
    return 0;
}

/*
Time Complexity: O(log.n)
Space Complexity: O(1)
*/