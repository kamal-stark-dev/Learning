// 211. Design Add and Search Words Data Structure

#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();

    bool dfs(int i, TrieNode* node, string word) {
        TrieNode* curr = node;

        for (int idx = i; idx < word.size(); idx++) {
            char c = word[idx];
            if (c == '.') {
                for (auto it: curr->children) {
                    char ch = it.first;
                    TrieNode* child = it.second;
                    if (dfs(idx + 1, child, word)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if (curr->children.find(c) == curr->children.end()) {
                    return false;
                }
                curr = curr->children[c];
            }
        }
        return curr->endOfWord;
    }
public:
    void addWord(string word) {
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
        return dfs(0, root, word);
    }
};

int main(void) {
    WordDictionary* d = new WordDictionary();

    d->addWord("bad");
    d->addWord("dad");
    d->addWord("mad");

    cout << "pad -> " << d->search("pad") << "\n";
    cout << "bad -> " << d->search("bad") << "\n";
    cout << ".ad -> " << d->search(".ad") << "\n";
    cout << "b.. -> " << d->search("b..") << "\n";

    return 0;
}

/*
L -> total number of nodes
n -> length of the word
A -> alphabet size (26 for `a-z`)

Time Complexity:
    - addWord: O(n)
    - search:
        - without '.': O(n)
        - with '.': worst case O(A ^ n) or O(L) depending on trie shape
Space Complexity: O(L)
*/