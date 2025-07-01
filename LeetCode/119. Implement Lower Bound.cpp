#include <iostream>
#include <vector>
using namespace std;

int findLowerBound(vector<int>& nums, int x) {
    int left = 0, right = nums.size() - 1;
    int idx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= x) {
            idx = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return idx;
}

int main(void) {
    vector<int> nums = {3, 8, 10, 15, 18};
    int x = 17;
    int lowerBoundIdx = findLowerBound(nums, x);

    cout << "Lower Bound is " << nums[lowerBoundIdx] << " present at index " << lowerBoundIdx << '\n';

    return 0;
}