// 387. First Unique Character in a String

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int firstUnique_dumb(string s) {
    unordered_map<char, int> m;
    queue<int> q;

    for (int i = 0; i < s.length(); i++) {
        if (m.find(s[i]) == m.end()) {
            q.push(i);
        }
        m[s[i]]++;
    }
    while (!q.empty()) {
        if (m[s[q.front()]] != 1) q.pop();
        else return q.front();
    }
    return -1;
}

int firstUnique(string s) {
    unordered_map<char, int> map;

    for (char c: s) map[c]++;

    for (int i = 0; i < s.length(); i++) {
        if (map[s[i]] == 1) return i;
    }
    return -1;
}

// 100% -> leetcode
int firstUnique_noMap(string s) {
    int frequency[26] = {0};

    for (char c: s) {
        frequency[c - 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (frequency[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

int main(void) {
    string s = "leetcode"; // 0
    string s = "aabb"; // -1

    cout << firstUnique_noMap(s) << endl;

    return 0;
}
/*
Time Complexity: O(1)
Time Complexity: O(n) -> map and queue, map | O(1) -> no map
*/