// 5. Longest Palindromic Substring

#include <iostream>
#include <vector> // for dp solution
using namespace std;

// O(n)
bool isPalindrome(const string& str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++; right--;
    }
    return true;
}

// O(n ^ 3)
string longestPalindrome_Brute(string s) {
    int n = s.size();
    if (n <= 1) return s;

    int max_len = 1;
    string max_str = s.substr(0, 1);

    for (int i = 0; i < n; i++) {
        for (int j = i + max_len; j <= n; j++) {
            if (j - i > max_len && isPalindrome(s.substr(i, j - i))) {
                max_len = j - i;
                max_str = s.substr(i, j - i);
            }
        }
    }
    return max_str;
}

// Dynamic Programming
string longestPalindrome_DP(string s) { // TC: O(n ^ 2), SC: O(n ^ 2)
    int n = s.size();
    int resIdx = 0, resLen = 0;

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;

                if (resLen < (j - i + 1)) {
                    resIdx = i;
                    resLen = j - i + 1;
                }
            }
        }
    }
    return s.substr(resIdx, resLen);
}

// O(n ^ 2) -> we check for palindromes from the middle and expand outwards
string longestPalindrome_Better(string s) {
    string res = "";
    int res_len = 0, n = s.length();

    for (int i = 0; i < n; i++) {
        // odd len palindromes
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if ((r - l + 1) > res_len) {
                res = s.substr(l, r - l + 1);
                res_len = r - l + 1;
            }
            l--; r++;
        }

        // even len palindromes
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if ((r - l + 1) > res_len) {
                res = s.substr(l, r - l + 1);
                res_len = r - l + 1;
            }
            l--; r++;
        }
    }
    return res;
}

int main(void) {
    string s = "babad";
    cout << "The longest palindromic string in `" << s << "` is `" << longestPalindrome_DP(s) << "`.\n";

    return 0;
}

/*
Time Complexity: O(n ^ 2)
Space Complexity: O(1) for computation, O(n) for output string
*/