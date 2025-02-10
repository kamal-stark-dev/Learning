// 39. Combination Sum

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> uniqueCombinations;
void findCombinations(vector<int>& nums, int target, vector<int>& combination, vector<vector<int>>& combinations, int idx) {
    if (target == 0) {
        if (uniqueCombinations.find(combination) != uniqueCombinations.end()) {
            return;
        }
        uniqueCombinations.insert(combination);
        combinations.push_back(combination);
        return;
    }
    if (idx == nums.size() || target < 0) return;

    combination.push_back(nums[idx]);
    // single
    findCombinations(nums, target - nums[idx], combination, combinations, idx + 1);
    // multiple
    findCombinations(nums, target - nums[idx], combination, combinations, idx);
    // exclide
    combination.pop_back();
    findCombinations(nums, target, combination, combinations, idx + 1);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> combinations;
    vector<int> combination;
    findCombinations(nums, target, combination, combinations, 0);
    return combinations;
}

void printCombinations(vector<vector<int>> combinations) {
    for (auto combination : combinations) {
        for (int num : combination) cout << num << " ";
        cout << endl;
    }
}

int main(void) {
    vector<int> nums = {2, 3, 5};
    int target = 8;

    vector<vector<int>> combinations = combinationSum(nums, target);
    printCombinations(combinations);

    return 0;
}