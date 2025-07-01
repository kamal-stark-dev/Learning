#include <iostream>
#include <vector>
using namespace std;

int findInsertedIdx(vector<int>& nums, int x) {
    int left = 0, right = nums.size() - 1;
    int idx = nums.size(); // if x is greater than any element
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= x){
            idx = mid;
            right = mid -1;
        }
        else left = mid + 1;
    }
    return idx;
}

int main(void) {
    vector<int> nums = {1, 2, 4, 7};
    int x = 5;

    int insertedIdx = findInsertedIdx(nums, x);
    cout << "The inserted index of " << x << " would be " << insertedIdx << '\n';

    return 0;
}