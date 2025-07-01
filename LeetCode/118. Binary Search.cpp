#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) right = mid;
        else left = mid + 1;
    }
    return -1;
}

int bsr(vector<int>& nums, int target, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (target == nums[mid]) return mid;
    else if (target > nums[mid]) return bsr(nums, target, mid + 1, right);
    else return bsr(nums, target, left, mid - 1);
}

int binarySearchRecursive(vector<int>& nums, int target) {
    return bsr(nums, target, 0, nums.size() - 1);
}

int main(void) {
    vector<int> nums = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 7;

    int idx = binarySearchRecursive(nums, target);

    if (idx == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << idx << endl;

    return 0;
}