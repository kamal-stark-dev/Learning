// 1539. Kth Missing Positive Number

#include <iostream>
#include <vector>
using namespace std;

int kthMissing(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1; // first and last indexes
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] - (mid + 1) >= k) right = mid - 1;
        else left = mid + 1;
    }
    return left + k;
}

int main(void) {
    vector<int> nums = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "The missing number at index(1-indexed) " << k << " is " << kthMissing(nums, k) << '\n';

    return 0;
}