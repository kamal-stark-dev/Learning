// 78. Subsets

#include <iostream>
#include <vector>
using namespace std;

void getSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& subsets) {
    if (i == nums.size()) {
        subsets.push_back(ans);
        return;
    }

    // include
    ans.push_back(nums[i]);
    getSubsets(nums, ans, i + 1, subsets);

    // exclude
    ans.pop_back();
    getSubsets(nums, ans, i + 1, subsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> ans;

    getSubsets(nums, ans, 0, subsets);

    return subsets;
}

int main(void) {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = subsets(nums);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}