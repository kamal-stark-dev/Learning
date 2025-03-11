// 1358. Number of Substrings Containing All Three Characters

#include<iostream>
#include<unordered_map>
using namespace std;

int numberOfSubstrings(string s) {
    int count = 0, left = 0;
    unordered_map<char, int> char_map = {{'a', 0}, {'b', 0}, {'c', 0}};

    int len = s.length();
    for (int right  = 0; right < len; right++) {
        char_map[s[right]]++;

        while (char_map['a'] > 0 && char_map['b'] > 0 && char_map['c'] > 0) {
            count += len - right;
            char_map[s[left]]--;
            left++;
        }
    }
    return count;
}

int main(void) {
    string s = "abcabc";
    cout << "Their are " << numberOfSubstrings(s) << " substrings containing 'abc'.\n";
    return 0;
}