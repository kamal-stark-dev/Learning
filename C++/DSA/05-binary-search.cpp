#include <iostream>
#include <vector>
using namespace std;

// Binary Search Algorithm
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

// Binary Search Recursive
int binarySearch_recursive(vector<int> nums, int start, int end, int target) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (target == nums[mid]) return mid;

        else if (target > nums[mid]) return binarySearch_recursive(nums, mid + 1, end, target);

        return binarySearch_recursive(nums, start, mid - 1, target);
    }
    return -1;
}

int main() {

    vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    int target = 5;

    int indexOfTarget = binarySearch_recursive(nums, 0, nums.size(), target);
    if (indexOfTarget == -1) cout << "target is not present in the array.\n";
    else cout << "target found at the index " << indexOfTarget << "\n";

    return 0;
}

/*
This is a searching technique which works for a sorted search space and has a time complexity of O(log.n)

- we can use binary search only on sorted arrays or strings
- divide and conquer approach
- time complexity of O(log.n)

n -> n/2 -> n/4 -> n/8 -> n/16 -> ... -> 1

    n / (2 ^ k) = 1
    n = 2 ^ k
    [log (base 2) on both sides]
    log n = log(2 ^ k) = k log(2) = k
    k = log.n

*/