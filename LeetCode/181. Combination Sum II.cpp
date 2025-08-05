// 40. Combination Sum II

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recursive(int idx, vector<int>& curr, int target, vector<int>& candidates, vector<vector<int>>& combinations) {
    if (target == 0) {
        combinations.push_back(curr);
        return;
    }

    for (int i = idx; i < candidates.size(); i++) {
        if (i > idx && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        curr.push_back(candidates[i]);
        recursive(i + 1, curr, target - candidates[i], candidates, combinations);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    recursive(0, curr, target, candidates, combinations);
    return combinations;
}

int main(void) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> combinations = combinationSum(candidates, target);

    for (auto combination: combinations) {
        for (int num: combination) cout << num << " ";
        cout << "\n";
    }

    return 0;
}

/*
Time Complexity: O(n logn) + O(2 ^ n * n)
Space Complexity: O(2 ^ n * n)
*/