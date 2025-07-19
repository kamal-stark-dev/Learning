// 151. Reverse Words in a String

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseString(string s) {
    int n = s.size();

    vector<string> words;
    string word = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            if (word.size() > 0) {
                words.push_back(word);
                word = "";
            }
            continue;
        }
        else word += s[i];
    }
    if (word.size() > 0) words.push_back(word);

    string ans;
    int size = words.size();
    for (int i = size - 1; i >= 0; i--) {
        ans += words[i];
        if (i != 0) ans += " ";
    }
    return ans;
}

string reverseString_Optimal(string s) {
    reverse(s.begin(), s.end());
    int n = s.size();
    string rev;

    for (int i = 0; i < n; i++) {
        string word = "";
        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.size() > 0) {
            rev += " " + word;
        }
    }
    return rev.substr(1); // remove the first " "
}

int main(void) {
    // string s = "  the sky   is blue   "; // "blue is sky the"
    string s = "the sky is blue";

    string revStr = reverseString_Optimal(s);
    cout << "Reverse String: " << revStr << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) in brute and O(1) in optimal
*/