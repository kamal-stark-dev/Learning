// 1910. Remove All Occurrences of a Substring - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include <iostream>
#include <string>
using namespace std;

string removeOccurences(string s, string part) {
    int part_size = part.size();

    while (s.find(part) < string::npos) { // can be replaced with `s.find(part) < s.length()`
        int idx = s.find(part);
        s.erase(idx, part_size);
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc", part = "abc";
    string result = removeOccurences(s, part);

    cout << result << endl;

    return 0;
}