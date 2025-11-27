// 49. Group Anagrams

#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs) {
    map<vector<int>, vector<string>> res; // or instead of vector<int> for frequency you can store the sorted string as the key
    for (string s: strs) {
        vector<int> freq(26, 0);
        for (char c: s) freq[c - 'a']++;
        res[freq].push_back(s);
    }

    vector<vector<string>> result;
    // for (auto &[key, group_anagram]: res) {result.push_back(group_anagram);}
    for (auto &pair: res) {
        result.push_back(pair.second);
    }
    return result;
}

int main(void) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> group_anagrams = groupAnagrams(strs);

    for (auto group: group_anagrams) {
        for (string anagram: group) cout << anagram << " ";
        cout << "\n";
    }

    return 0;
}

/*
n -> number of strings
m -> average size of strings

Time Complexity: O(n * m * logn)
Space Complexity: O(n * m)
*/