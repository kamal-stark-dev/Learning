// 128. Longest Consecutive Sequence

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int largestConsecutive_Brute(vector<int> nums) { // TC: O(n ^ 2), SC: O(n)
    unordered_set<int> st(nums.begin(), nums.end());

    int longest = 0;
    for (int n: st) {
        int len = 1;
        while (st.find(n + len) != st.end()) len++;
        longest = max(longest, len);
    }
    return longest;
}

int largestConsecutive_Sorting(vector<int> nums) { // TC: O(n logn), SC: O(1 | n) -> depending on the sorting algorithm
    sort(nums.begin(), nums.end());

    int longest = 0, curr = nums[0], i = 0, streak = 0;

    while (i < nums.size()) {
        if (curr != nums[i]) {
            curr = nums[i];
            streak = 0;
        }
        while (i < nums.size() && curr == nums[i]) { // skip duplicates
            i++;
        }
        streak++;
        curr++;
        longest = max(streak, longest);
    }
    return longest;
}

int largestConsecutive(vector<int> nums) { // TC: O(n), SC: O(n)
    unordered_set<int> st(nums.begin(), nums.end());

    int longest = 0;
    for (int n: st) { // for each element in set (to prevent duplicate checks)
        if (st.find(n - 1) == st.end()) { // if element is the first in the sequence
            int length = 1;
            while (st.find(n + length) != st.end()) {
                length++;
            }
            longest = max(length, longest);
        }
    }
    return longest;
}

int main(void) {
    vector<int> nums = {100, 4, 200, 1, 3, 2, 5}; // 5

    cout << "The longest consecutive sequence is of length: " << largestConsecutive_Sorting(nums) << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/