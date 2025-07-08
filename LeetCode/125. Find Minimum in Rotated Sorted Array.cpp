#include <iostream>
#include <vector>
using namespace std;

bool findMinimum(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) { // min in right side
            left = mid + 1;
        }
        else right = mid; // not `mid - 1` because mid could be the minimum
    }
    return nums[left];
}

int main(void) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << "The minimum element in the array is: " << findMinimum(nums) << endl;

    return 0;
}