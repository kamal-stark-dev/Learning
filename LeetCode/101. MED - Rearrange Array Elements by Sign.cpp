// 2149. Rearrange Array Elements by Sign

#include <iostream>
#include <vector>
using namespace std;

void rearrangeArray_Brute(vector<int>& nums) {
    int size = nums.size();

    vector<int> positives, negatives;

    for (int n : nums) {
        if (n < 0) negatives.push_back(n);
        else positives.push_back(n);
    }

    for (int i = 0; i < size / 2; i++) {
        nums[i * 2] = positives[i];
        nums[i * 2 + 1] = negatives[i];
    }
}

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size());
    int pos = 0, neg = 1;

    for (int n : nums) {
        if (n < 0) {
            ans[neg] = n;
            neg += 2;
        }
        else {
            ans[pos] = n;
            pos += 2;
        }
    }
    return ans;
}

int main(void) {
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    // rearrangeArray(nums);
    // for (int n : nums) cout << n << " ";

    vector<int> ans = rearrangeArray(nums);
    for (int n : ans) cout << n << " ";

    return 0;
}

/*
Time Complexity:
    Brute: O(2 * n) => O(n)
    Optimal: O(n)

Space Complexity:
    Brute: O(n / 2) + O(n / 2) => O(n), positives and negatives
    Optimal: O(n), result list
*/