#include <iostream>
#include <vector>
using namespace std;

int findUpperBound(vector<int>& nums, int x) {
    int left = 0, right = nums.size() - 1;
    int idx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > x) {
            idx = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return idx;
}

int main(void) {
    vector<int> nums = {3, 8, 10, 15, 18};
    int x = 10;
    int upperBoundIdx = findUpperBound(nums, x);

    cout << "Upper Bound is " << nums[upperBoundIdx] << " present at index " << upperBoundIdx << '\n';

    return 0;
}