// 260. Single Number III

#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int xorr = 0, n1 = 0, n2 = 0;

    for (int num: nums) xorr ^= num;
    int rightmost = xorr & (~((long) xorr - 1));

    for (int num: nums) {
        if (num & rightmost) n1 ^= num;
        else n2 ^= num;
    }

    return {n1, n2};
}

int main(void) {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = singleNumber(nums);

    cout << ans[0] << " and " << ans[1] << "\n";

    return 0;
}

/*
Time Complexity: O(2 * n) -> O(n)
Space Complexity: O(1)
*/