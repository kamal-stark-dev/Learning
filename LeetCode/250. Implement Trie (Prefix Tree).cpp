// 208. Implement Trie (Prefix Tree)

#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};

class Trie {
private:
    TrieNode* root = new TrieNode;
public:
    Trie() {}

    void insert(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

int main(void) {
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << "\n"; // true
    cout << t.search("app") << "\n"; // false
    cout << t.startsWith("app") << "\n"; // true

    return 0;
}

/*
n -> length of the string passed
t -> total number of nodes in the trie

Time Complexity: O(n)
Space Complexity: O(t)
*/