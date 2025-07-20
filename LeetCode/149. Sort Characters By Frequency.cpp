// 451. Sort Characters By Frequency

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

static bool cmp(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

// Time: O(n * log n), Space: O(n)
string frequencySort(string s) {
    unordered_map<char, int> mpp;
    for (char c: s) mpp[c]++; // O(n)

    vector<pair<char, int>> vec(mpp.begin(), mpp.end());
    sort(vec.begin(), vec.end(), cmp); // O(n * log n)

    string res;
    for (auto it: vec) {
        string part(it.second, it.first);
        res += part;
    }
    return res;
}

// Priority Queue Solution
string frequencySort_PriorityQueue(string s) {
    auto cmp = [](pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    };

    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
    unordered_map<char, int> mpp;

    for (char c: s) mpp[c]++;
    for (auto& it: mpp) {
        pq.push(make_pair(it.first, it.second));
    }

    string res;
    while (!pq.empty()) {
        pair<char, int> p = pq.top();
        pq.pop();
        res.append(p.second, p.first);
    }
    return res;
}

// Multimap Solution -
// Time: O(n + k log k) -> practically O(n) and Space: O(n + k) -> practically O(n)
// n -> size of string, k -> <= 128 or <= 256 for ASCII / extended ASCII
string frequencySort_Multimap(string s) {
    unordered_map<char, int> mpp;
    for (char c: s) mpp[c]++;

    multimap<int, char> mm;
    for (auto it: mpp) {
        mm.insert({it.second, it.first});
    }

    string res;
    for (auto it = mm.rbegin(); it != mm.rend(); it++) {
        res += string(it->first, it->second);
    }
    return res;
}

int main(void) {
    string s = "tree";
    string sortedStr = frequencySort_Multimap(s);
    cout << "The string `" << s << "` becomes `" << sortedStr << "` when sorted by frequency(desc).\n";

    return 0;
}

/*
Time Complexity: O(n * log n)
Space Complexity: O(n)
*/