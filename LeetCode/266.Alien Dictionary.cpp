// Alien Dictionary - https://neetcode.io/problems/foreign-dictionary/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string order;

    bool dfs(char c) { // O(V + K) -> O(26) -> O(1)
        if (visited.find(c) != visited.end()) {
            return visited[c];
        }

        visited[c] = false; // visiting
        for (int nei: adj[c]) {
            if (!dfs(nei)) return false; // cycle detected
        }
        visited[c] = true; // visited
        order.push_back(c);
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        for (string word: words) { // O(N . L)
            for (char c: word) adj[c]; // initializing
        }

        for (int i = 0; i < words.size() - 1; i++) { // O(N . L)
            string w1 = words[i], w2 = words[i + 1];
            size_t minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2) {
                return "";
            }
            for (size_t j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for (auto pair: adj) { // O(26) -> O(1)
            if (!dfs(pair.first)) return "";
        }
        reverse(order.begin(), order.end()); // O(K) -> O(26) -> O(1)
        return order;
    }
};

int main(void) {
    vector<string> words = {"hrn", "hrf", "er", "enn", "rfnn"};
    Solution s;
    string orderOfLetters = s.foreignDictionary(words);

    cout << orderOfLetters << "\n";

    return 0;
}

/*
N -> no. of words
L -> avg. size of each word
K -> no. of unique letters
V -> no. of vertices

Time Complexity: O(N . L + V + K) -> O(N . L) as K <= 26
Space Complexity: O(K + E), again K <= 26 -> O(1)
*/