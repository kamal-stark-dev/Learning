// Longest Consecutive Subsequence - https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int> nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int longest = 0;
    unordered_set<int> st;

    for (int n: nums) {
        st.insert(n);
    }

    for (int n: st) {
        if (st.find(n - 1) == st.end()) { // possible start of the series
            int el = n;
            int count = 0;
            while (st.find(el) != st.end()) {
                count++;
                el += 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main(void) {
    vector<int> nums = {2, 6, 1, 9, 4, 5, 3};
    int longestCount = longestSubsequence(nums);
    cout << longestCount << endl;

    return 0;
}

/*
Time Complexity:
    Better Version: O(n logn) + O(n) -> if we use the sort approach
    Optimal Version: O(n) + O(n) -> if no collision occurs

Space Complexity:
    Better Version: O(1)
    Optimal Version: O(n) -> unordered_set
*/