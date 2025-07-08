#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return true;
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
            continue;
        }
        else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target <= nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        else {
            if (nums[mid] <= target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return false;
}

int main(void) {
    vector<int> nums = {3, 1, 2, 3, 3, 3, 3};
    int target = 2;

    if (search(nums, target) != -1) cout << target << " is present in the array.\n";
    else cout << target << " is not present in the array.\n";

    return 0;
}