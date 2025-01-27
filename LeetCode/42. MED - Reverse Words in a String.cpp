// 151. Reverse Words in a String - https://leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        string word = "";
        while (i < n && s[i] != ' ') {
            word += s[i++];
        }
        reverse(word.begin(), word.end());

        if (word.length() > 0) ans += " " + word; // we added the len > 0 check so that it doesn't add an empty string("") as " " will also be added.
    }
    return ans.substr(1); // to remove the first ' ' at 0th index
}

int main() {
    string s = "  hello world   "; // should output - "world hello"
    string rev = reverseWords(s);

    cout << rev << endl;

    return 0;
}