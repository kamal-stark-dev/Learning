// Split Array - Largest Sum (Direct Variation of Book Allocation)

#include <iostream>
#include <vector>
using namespace std;

int minimizedSum(vector<int>& nums, int k) { //
    int left = 0, right = 0;
    int n = nums.size();
    if (n < k) return -1;
    for (int num: nums) { // O(N)
        left = max(left, num);
        right += num;
    }

    while (left <= right) { // O(N * log R), R -> [max(nums), sum(nums)]
        int mid = left + (right - left) / 2;

        int count = 1;
        long long sum = nums[0];
        for (int i = 1; i < n; i++) { // O(N)
            if (sum + nums[i] <= mid) sum += nums[i];
            else {
                count++;
                sum = nums[i];
            }
        }
        if (count <= k) right = mid - 1;
        else left = mid + 1;
    }
    return left;
 }

int main(void) {
    vector<int> nums = {3, 5, 1};
    int k = 3;

    // we need to minimize the largest sum
    cout << "The minimized largest sum such that array is split into " << k << " parts is " << minimizedSum(nums, k) << ".\n";

    return 0;
}

/*
Time Complexity: O(N * log R) + O(N)
Space Complexity: O(1)
*/