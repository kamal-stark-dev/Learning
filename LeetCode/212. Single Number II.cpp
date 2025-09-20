// 137. Single Number II

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(const vector<int>& nums) {
    int ans = 0, n = nums.size();

    for (int idx = 0; idx < 32; idx++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & (1 << idx)) {
                count++;
            }
        }
        if (count % 3 == 1) {
            ans |= (1 << idx); // set idx-th bit
        }
    }
    return ans;
}

int main(void) {
    vector<int> nums = {2, 2, 2, 4, 3, 4, 4};

    cout << "Single Number: " << singleNumber(nums) << "\n";

    return 0;
}

/*
Time Complexity: O(32 * n) -> O(n)
Space Complexity: O(1)
*/