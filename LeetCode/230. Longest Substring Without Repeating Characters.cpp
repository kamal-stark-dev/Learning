// 3. Longest Substring Without Repeating Characters

#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<int> st;
    int res = 0, left = 0;

    for (int right = 0; right < s.size(); right++) {
        while (st.find(s[right]) != st.end()) {
            st.erase(s[left++]);
        }
        st.insert(s[right]);
        res = max(res, right - left + 1);
    }
    return res;
}

int main(void) {
    string s = "abcabcbb";

    cout << "The longest substring with no repeating characters is of size: " << lengthOfLongestSubstring(s) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/