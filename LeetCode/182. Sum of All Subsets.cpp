// Sum of All Subsets

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetSumPrint(int i, vector<int>& nums, int sum, vector<int>& curr, vector<int>& ans) {
    if (i == nums.size()) {
        ans.push_back(sum);
        return;
    }

    curr.push_back(nums[i]);
    subsetSumPrint(i + 1, nums, sum + nums[i], curr, ans);

    curr.pop_back();
    subsetSumPrint(i + 1, nums, sum, curr, ans);
}

int main(void) {
    vector<int> nums = {1, 2, 5};

    // to be done
    vector<int> sums, temp;
    subsetSumPrint(0, nums, 0, temp, sums);

    sort(sums.begin(), sums.end());
    for (int sum: sums) {
        cout << sum << " ";
    }
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(2 ^ n) + O(2 ^ n log(2 ^ n)), each index has two ways making it 2 ^ n and for sorting we need quasilinear time.
Space Complexity: O(2 ^ n), recursion stack.
*/