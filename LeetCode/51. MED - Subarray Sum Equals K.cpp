// 560. Subarray Sum Equals K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC: O(n ^ 2) & SC: O(1)
int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) { // starting point
        int sum = 0;
        for (int j = i; j < size; j++) { // ending point
            sum += nums[j];
            if (sum == k) count++;
        }
    }
    return count;
}

// TC: O(n) & SC: O(n)
int subarraySum_PrefixSum(vector<int>& nums, int k) {
    int size = nums.size();
    int count = 0;
    vector<int> prefixSum (size, 0);

    prefixSum[0] = nums[0];
    for (int i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    unordered_map<int, int> m; // <PS, freq>
    for (int i= 0; i < size; i++) {
        if (prefixSum[i] == k) count++;

        int val = prefixSum[i] - k;
        if (m.find(val) != m.end()) {
            count += m[val];
        }
        if (m.find(prefixSum[i]) == m.end()) {
            m[prefixSum[i]] = 0;
        }
        m[prefixSum[i]]++;
    }
    return count;
}

int main(void) {
    vector<int> nums = {9, 4, 20, 3, 10, 5};
    int k = 33;

    int subarraySumCount = subarraySum_PrefixSum(nums, k);
    cout << "There are " << subarraySumCount << " subarrays adding up to " << k << endl;

    return 0;
}