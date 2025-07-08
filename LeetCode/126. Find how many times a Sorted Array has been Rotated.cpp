#include <iostream>
#include <vector>
using namespace std;

int findRotateCount(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) { // min in right side
            left = mid + 1;
        }
        else right = mid; // not `mid - 1` because mid could be the minimum
    }
    return left;
}

int main(void) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // just find the index of minimum element as the index will tell how many times it has been rotated
    cout << "The array has been rotated " <<  findRotateCount(nums) << " times\n";

    return 0;
}