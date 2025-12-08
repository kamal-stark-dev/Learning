// 39. Combination Sum

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findCombinations(int startIdx, vector<int>& curr, int target, const vector<int>& candidates, vector<vector<int>>& combinations) {
    if (target == 0) {
        combinations.push_back(curr);
        return;
    }

    for (int currIdx = startIdx; currIdx < candidates.size(); currIdx++) {
        // if (target < 0) {
        //     return;
        // }
        int num = candidates[currIdx];
        if (num > target) continue;

        curr.push_back(num);
        findCombinations(currIdx, curr, target - num, candidates, combinations);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> curr;
    findCombinations(0, curr, target, candidates, combinations);
    return combinations;
}

void printCombinations(vector<vector<int>> combinations) {
    for (auto combination : combinations) {
        for (int num : combination) cout << num << " ";
        cout << "\n";
    }
}

int main(void) {
    vector<int> candidates = {2, 3, 5};
    int target = 8;

    vector<vector<int>> combinations = combinationSum(candidates, target);
    printCombinations(combinations);

    return 0;
}

/*
Time Complexity: O(N ^ (T / min(candidates)))
Space Complexity: O(T / min(candidates))
*/