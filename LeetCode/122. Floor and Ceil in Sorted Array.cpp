#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findFloorAndCeil(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    int idx = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            idx = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    int ceil = -1, floor = -1;
    if (idx != n) ceil = nums[idx];
    else idx--;

    while (idx >= 0) {
        if (nums[idx] < target) {
            floor = nums[idx];
            break;
        }
        idx--;
    }

    return {floor, ceil};
}

int findFloor(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target) {
            floor = nums[mid];
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return floor;
}

int findCeil (vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            ceil = nums[mid];
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return ceil;
}

pair<int, int> findFloorAndCeil_2(vector<int>& nums, int target) {
    int floor = findFloor(nums, target); // lowerbound
    int ceil = findCeil(nums, target); // upperbound
    return {floor, ceil};
}

int main(void) {
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;

    // find lower bound for ceil and then move back till you reach an element < x for floor
    pair<int, int> ans = findFloorAndCeil_2(nums, x);
    cout << "Floor: " << ans.first << "\nCeil: " << ans.second << '\n';

    return 0;
}