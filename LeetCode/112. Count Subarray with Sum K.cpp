#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subarrayCountWithSumK_Brute(vector<int> nums, int k) {
    int n = nums.size(), count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) count++;
        }
    }
    return count;
}

int subarrayCountWithSumK(vector<int> nums, int k) {
    int n = nums.size();
    map<int, int> mpp;
    int preSum = 0, count = 0;

    mpp[0] = 1;
    for (int i = 0; i < n; i++) {
        preSum += nums[i];
        int rem = preSum - k;
        count += mpp[rem];
        mpp[preSum] += 1;
    }
    return count;
}

int main(void) {
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;

    cout << subarrayCountWithSumK(nums, k) << '\n';
    return 0;
}