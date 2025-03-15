// 2560. House Robber IV

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCapability(vector<int> nums, int k) {
    int minReward = 1, maxReward = *max_element(nums.begin(), nums.end());
    int totalHouses = nums.size();

    while (minReward < maxReward) {
        int midReward = (minReward + maxReward) / 2;
        int possibleThefts = 0;

        for (int i = 0; i < totalHouses; i++) {
            if (nums[i] <= midReward) {
                possibleThefts += 1;
                i++; // skip the next house
            }
        }

        if (possibleThefts >= k) maxReward = midReward;
        else minReward = midReward + 1;
    }
    return minReward;
}

int main(void) {
    vector<int> nums = {2, 3, 5, 9};
    int k = 2;

    cout << "The minimum capacility of the robber out of all possible ways to steal at least " << k << " is " << minCapability(nums, k) << ".\n";

    return 0;
}
/*
Time Complexity: O(n logn)
Space Complexity: O(1)
*/