#include <bits/stdc++.h>
using namespace std;

/*
Brute: the brute solution would be to use check for each <i> if nums[i] > nums[j] (j -> i + 1 to n) [[ O(n ^ 2) ]]
Optimal: traverse from the back and maintian currMax value, if a greater value occurs it's a leader [[ O(n) ]]
*/

int main(void) {
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    int n = nums.size();
    int currLeader = nums[n - 1];
    vector<int> leaders = {currLeader};

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] > currLeader) {
            currLeader = nums[i];
            leaders.push_back(nums[i]);
        }
    }

    cout << "Leaders: ";
    for (int n: leaders) cout << n << " ";
    return 0;
}