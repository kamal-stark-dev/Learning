// 852. Peak Index in a Mountain Array - https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <iostream>
#include <vector>
using namespace std;

// you need to find the element in log.n time complexity
int peakElement(vector<int> nums) {
    int left = 1, right = nums.size() - 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) return mid;

        else if (nums[mid - 1] < nums[mid]) left = mid + 1;

        else right = mid - 1;
    }

    return -1;
}

/*
> > > | < <
0 3 8 9 5 2
0 1 2 3 4 5

l = 0, r = 5
m = 2
0 <= 8 -> True
l = m + 1 = 3

l = 3, r = 5
m = 4
9 !<= 5 -> return left
*/

int main(void) {
    // vector<int> nums = {0, 3, 8, 9, 5, 2};
    vector<int> nums = {24,69,100,99,79,78,67,36,26,19};

    int peakIndex = peakElement(nums);

    cout << "The peak element is " << nums[peakIndex] << " present at the " << peakIndex << " index.\n";

    return 0;
}
