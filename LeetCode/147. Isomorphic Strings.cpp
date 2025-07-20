// 205. Isomorphic Strings

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) { // O(n) -> using two maps
    if (s.size() != t.size()) return false; // it's given though that they are of same size
    int n = s.size();

    unordered_map<char, int> smap, tmap;
    for (int i = 0; i < n; i++) {
        if (smap.find(s[i]) == smap.end()) {
            smap[s[i]] = i;
        }
        if (tmap.find(t[i]) == tmap.end()) {
            tmap[t[i]] = i;
        }
        if (smap[s[i]] != tmap[t[i]]) {
            return false;
        }
    }
    return true;
}

bool isIsomorphic_2(string s, string t) { // O(n ^ 2) -> using one map
    unordered_map<char, char> char_map;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (char_map.find(s[i]) != char_map.end()) {
            if (char_map[s[i]] != t[i]) return false;
        }
        else {
            for (auto it: char_map) {
                if (it.second == t[i]) return false;
            }
        }
        char_map[s[i]] = t[i];
    }
    return true;
}

/*
There is also a single liner for the same in python:
> `return len(set(s)) == len(set(t)) == len(set(zip(s, t)))`
*/

int main(void) {
    string s = "zoro", t = "kimi";
    cout << "The strings `" << s << "` and `" << t << "` are" << (isIsomorphic_2(s, t) ? "": " not") << " isomorphic.\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/