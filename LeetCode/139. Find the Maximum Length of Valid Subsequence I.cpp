// 3201. Find the Maximum Length of Valid Subsequence I

#include <iostream>
#include <vector>
#include <algorithm> // for max({})
using namespace std;

int maximumLength(vector<int>& nums) {
    int even = 0, odd = 0, both = 1;
    int parity = nums[0] % 2;

    for (int num: nums) {
        if (num % 2 == 0) even++;
        else odd++;
        if (num % 2 != parity) {
            both++;
            parity = 1 - parity;
        }
    }
    return max({even, odd, both});
}

int main(void) {
    vector<int> nums = {1, 2, 1, 1, 2, 1, 2};

    cout << "Maximum length of valid subsequence is " << maximumLength(nums) << "\n";

    return 0;
}