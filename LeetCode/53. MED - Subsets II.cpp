// 90. Subsets II

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& subsets) {
    if (i == nums.size()) {
        subsets.push_back(ans);
        return;
    }

    // include
    ans.push_back(nums[i]);
    findSubsets(nums, ans, i + 1, subsets);

    ans.pop_back();

    // increment idx while the next elements are same
    int idx = i + 1;
    while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

    // exclude
    findSubsets(nums, ans, idx, subsets);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // sort the nums to get all the same elements together
    sort(nums.begin(), nums.end());

    vector<vector<int>> uniqueSubsets;
    vector<int> ans;

    findSubsets(nums, ans, 0, uniqueSubsets);
    return uniqueSubsets;
}

int main(void) {
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> subsets = subsetsWithDup(nums);

    for (int i = 0; i < subsets.size(); i++) {
        for (int j = 0; j < subsets[i].size(); j++) {
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Time Complexity: O(n.logn + 2 ^ n * n) ==> O(2 ^ n * n)
Space Complexity: O(2 ^ n * n) --> as there will be this many nodes
*/