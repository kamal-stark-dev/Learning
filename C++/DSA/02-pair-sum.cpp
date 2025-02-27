// Pair Sum - Easy

#include <iostream>
#include <vector>
using namespace std;

// Brute Force - O(n^2)
vector<int> pairSum(vector<int>& nums, int target) {
    vector<int> res;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        int check = target - nums[i];
        for (int j = i + 1; j < size; j++) {
            if (nums[j] == check) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }

    return res;
}

// Optimized (Two Pointer Approach) - using the fact that the array is sorted - Time Complexity is O(n)
vector<int> pairSumOptimized(vector<int>& nums, int target) {
    vector<int> res;
    int size = nums.size();

    int i = 0, j = size - 1;

    while (i < j) {
        int pairSum = nums[i] + nums[j];
        if (pairSum == target) {
            res.push_back(i);
            res.push_back(j);
            return res;
        }
        else if (pairSum < target)
            i++;
        else
            j++;
    }

    return res;
}

int main(void) {

    vector<int> nums = {2, 7, 9, 11};
    int target = 20;

    vector<int> res = pairSumOptimized(nums, target);

    if (res.size() == 0)
        cout << "Their is no pair in the array that adds up to " << target << endl;
    else
        cout << "Found at indexes: " << res[0] << " & " << res[1] << endl;

    return 0;
}