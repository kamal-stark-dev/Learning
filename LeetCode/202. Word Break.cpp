// 139. Word Break

#include <iostream>
#include <vector>
using namespace std;

bool wordBreak(string s, vector<string> wordDict) {
    int n = s.size();

    vector<bool> dp(n + 1, false);
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (string word: wordDict) {
            if (i + word.size() <= n && s.substr(i, word.size()) == word) // we have enough characters to compare with word
                dp[i] = dp[i + word.size()];
            if (dp[i])
                break;
        }
    }

    return dp[0];
}

// same thing but if you want to loop from 0 to n

bool wordBreak_2(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (string word: wordDict) {
            int start = i - word.size();
            if (start >= 0  && dp[start] && s.substr(start, word.size()) == word) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

int main(void) {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    cout << (wordBreak_2(s, wordDict) ? "True": "False") << "\n";

    return 0;
}

/*
Time Complexity: O(n * m), n -> hashset size, m -> size of words
Space Complexity: O(n + kL), L -> average length of word
*/