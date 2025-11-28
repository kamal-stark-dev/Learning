// 76. Minimum Window Substring

#include <iostream>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    if (t.size() == 0) return "";

    unordered_map<int, int> window, countT;
    for (char c: t) countT[c]++;

    int have = 0, need = countT.size();
    int l = 0, resLen = INT_MAX, resStart = 0;

    for (int r = 0; r < s.size(); r++) {
        window[s[r]]++;
        if (countT.find(s[r]) != countT.end() && countT[s[r]] == window[s[r]]) {
            have++;
        }

        while (have == need) {
            int len = r - l + 1;
            if (len < resLen) {
                resLen = len;
                resStart = l;
            }
            window[s[l]]--;
            if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                have--;
            }
            l++;
        }
    }
    return (resLen == INT_MAX) ? "": s.substr(resStart, resLen);
}

int main(void) {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << "Minimum Window Substring: " << minWindow(s, t) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/