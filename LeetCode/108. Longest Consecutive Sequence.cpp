#include <bits/stdc++.h>
using namespace std;

bool consecutiveIsThere(vector<int> nums, int term) { // O(n)
    for (int n: nums) {
        if (n == term) return true;
    }
    return false;
}

int longestConsecutiveSequence_Brute(vector<int> nums) { // O(n ^ 2)
    int n = nums.size(), maxLen = 1;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int count  = 1;
        while (consecutiveIsThere(nums, num + 1)) {
            num += 1;
            count += 1;
        }
        maxLen = max(maxLen, count);
    }

    return maxLen;
}

int longestConsecutiveSequence_Better(vector<int> nums) { // O(n logn)
    int n = nums.size();
    if (n <= 1) return n;
    sort(nums.begin(), nums.end());

    int maxLen = 0, len = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] == nums[i]) continue; // [1, 1, 1, 2, 2, 3] -> should count only once
        if (nums[i - 1] + 1 == nums[i]) {
            len++;
        }
        else len = 1;
        maxLen = max(maxLen, len);
    }

    return maxLen;
}

int longestConsecutiveSequence_Optimal(vector<int> nums) { // O(n + 2n) ~> O(3n) -> O(n)
    int maxLen = 0;
    unordered_set<int> st;

    for (int n: nums) { // O(n)
        st.insert(n);
    }

    for (int it: st) {
        if (st.find(it - 1) == st.end()) { // check if it's a starting element or not
            int count = 1;
            int num = it;
            while (st.find(num + 1) != st.end()) {
                count++;
                num++;
            }
            maxLen = max(maxLen, count);
        }
    }
    return maxLen;
}

int main(void) {
    vector<int> nums = {100, 200, 2, 3, 1, 4, 101, 1, 1, 2, 2}; // longest consecutive sequence is -> 1 2 3 4

    // cout << "Longest Consecutive Length: " << longestConsecutiveSequence_Brute(nums) << '\n';
    // cout << "Longest Consecutive Length: " << longestConsecutiveSequence_Better(nums) << '\n';
    cout << "Longest Consecutive Length: " << longestConsecutiveSequence_Optimal(nums) << '\n';

    return 0;
}
