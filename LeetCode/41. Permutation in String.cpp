#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkFreq(vector<int> f1, vector<int> f2) {
    int size = f1.size();

    for (int i = 0; i < 26; i++)
        if (f1[i] != f2[i]) return false;
    return true;
}

bool checkInclusion(string s1, string s2) {
    // create frequency table for `s1`
    vector<int> freq (26, 0);
    for (char c: s1) freq[c - 'a']++;

    // checking frequency for every window possible
    int window_size = s1.length();
    for (int i = 0; i < s2.length(); i++) {
        int window_idx = 0, idx = i;
        vector<int> win_freq (26, 0);

        while (window_idx < window_size && idx < s2.length()) {
            win_freq[s2[idx] - 'a']++;
            window_idx++; idx++;
        }

        if (checkFreq(freq, win_freq)) return true;
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (checkInclusion(s1, s2)) cout << "True\n";
    else cout << "False\n";
}