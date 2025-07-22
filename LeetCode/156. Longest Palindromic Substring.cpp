// 5. Longest Palindromic Substring

#include <iostream>
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

// O(n ^ 2) -> this can be done by changing the logic to check for palindromes
string longestPalindrome_Better(string s) {
    string res = "";
    int res_len = 0, n = s.length();

    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if ((r - l + 1) > res_len) {
                res = s.substr(l, r - l + 1);
                res_len = r - l + 1;
            }
            l--; r++;
        }

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
    cout << "The longest palindromic string in `" << s << "` is `" << longestPalindrome_Better(s) << "`.\n";

    return 0;
}