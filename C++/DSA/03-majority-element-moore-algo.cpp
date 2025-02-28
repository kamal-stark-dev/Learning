#include <iostream>
#include <vector>
#include <algorithm>  // for sorting approach, not moore's algo
using namespace std;

/*
You need to find an element which has the moer frequency than the floor of size of array divided by two.
    `frequency(ans) > size / 2`
- Given that their is a mojority element present in the array.
*/

// Moore's Algorithm -> O(n)
int majorityElementMooresVotingAlgo(vector<int> nums) {
    int freq = 0, ans = nums[0];

    for (int i: nums) {
        if (freq == 0) ans = i;
        if (ans == i) freq++;
        else freq--;
    }

    // If we don't know if the majority element exists or not then add below code
    int count = 0;
    for (int num: nums) {
        if (ans == num) count++;
    }

    return count > nums.size() / 2 ? ans : -1;
}

// Sorting Method -> O(n.logn)
int majorityElementSort(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    return nums[size / 2];
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // vector<int> nums = {1, 2, 3, 4, 4}; // should give -1

    cout << "The majority element (by Moore's) is: " << majorityElementMooresVotingAlgo(nums) << endl;
    cout << "The majority element (by sorting) is: " << majorityElementSort(nums) << endl;
    return 0;
}