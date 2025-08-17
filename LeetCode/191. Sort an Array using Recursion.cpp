// Sort an Array using Recursion

#include <iostream>
#include <vector>
using namespace std;

void sortRecursive(vector<int>& nums, int i = 0) {
    int n = nums.size();
    if (i >= n) return;

    int minIdx = i;
    for (int idx = i + 1; idx < n; idx++) {
        if (nums[idx] < nums[minIdx]) minIdx = idx;
    }
    swap(nums[i], nums[minIdx]);
    sortRecursive(nums, i + 1);
}

int main(void) {
    vector<int> nums = {4, 3, 7, 1, 2, 5, 6};
    sortRecursive(nums);

    for (int n: nums) cout << n << " ";
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(n ^ 2), [(n * (n + 1)) / 2] to be more precise
Space Complexity: O(n), recursion stack
*/