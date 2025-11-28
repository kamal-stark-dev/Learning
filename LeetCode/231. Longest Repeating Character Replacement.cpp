// 424. Longest Repeating Character Replacement

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int characterReplacement_26N(string s, int k) { // TC: O(26 * n), SC: O(26)
    vector<int> counts(26, 0);
    int l = 0, longest = 0;

    for (int r = 0; r < s.size(); r++) {
        counts[s[r] - 'A']++;

        if ((r - l + 1) - *max_element(counts.begin(), counts.end()) > k) {
            counts[s[l] - 'A']--;
            l++;
        }
        longest = max(longest, r - l + 1);
    }
    return longest;
}

int characterReplacement(string s, int k) { // TC: O(n), SC: O(26)
    vector<int> counts(26, 0);
    int l = 0, maxf = 0, longest = 0;

    for (int r = 0; r < s.size(); r++) {
        counts[s[r] - 'A']++;
        maxf = max(maxf, counts[s[r] - 'A']);

        if ((r - l + 1) - maxf > k) {
            counts[s[l] - 'A']--;
            l++;
        }
        longest = max(longest, r - l + 1);
    }
    return longest;
}

int main(void) {
    string s = "ABAB";
    int k = 2;

    cout << "The longest repeating character length after replacing " << k << " letters is: " << characterReplacement(s, k) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/