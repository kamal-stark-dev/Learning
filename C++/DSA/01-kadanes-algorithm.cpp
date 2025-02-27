// Maximum Subarray Sum - Kadane's Algorithm

#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(vector<int>& nums) {
    int maxSum = INT_MIN, currSum = 0;

    for (int num: nums) {
        currSum += num;
        maxSum = max(maxSum, currSum);

        if (currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int main(void) {
    vector<int> nums = {1, 2, -4, 5, 6, -2}; // should be 11
    cout << maxSubarray(nums) << endl;

    return 0;
}