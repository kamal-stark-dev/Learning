// 212. Word Search II

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class Trie {
private:
public:
    TrieNode* root = new TrieNode();
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
};

void dfs(int r, int c, TrieNode* node, string word, vector<vector<char>>& board, vector<string>& words, vector<string>& res) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
        return;
    }
    char ch = board[r][c];
    if (node->children.find(ch) == node->children.end()) {
        return;
    }

    node = node->children[ch];
    word += ch;
    if (node->endOfWord) {
        res.push_back(word);
        node->endOfWord = false;
    }

    board[r][c] = '$';
    dfs(r + 1, c, node, word, board, words, res);
    dfs(r - 1, c, node, word, board, words, res);
    dfs(r, c + 1, node, word, board, words, res);
    dfs(r, c - 1, node, word, board, words, res);
    board[r][c] = ch;
}

vector<string> wordsSearch(vector<vector<char>>& board, vector<string>& words) {
    Trie* trie = new Trie();
    for (string word: words) {
        trie->insert(word);
    }
    vector<string> res;
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[0].size(); c++) {
            if (trie->root->children.find((board[r][c])) != trie->root->children.end()) {
                dfs(r, c, trie->root, "", board, words, res);
            }
        }
    }
    return res;
}

int main(void) {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> wordsFound = wordsSearch(board, words);

    for (string word: wordsFound) {
        cout << word << " ";
    }
    cout << "\n";

    return 0;
}

/*
K -> number of words
L -> max word length

Time Complexity: O(K * L + M * N * L)
    - inserting all words: O(K * L)
    - dfs: O(M * N * L)

Space Complexity: O(K * L)
    - trie storage: O(K * L)
    - recursion: O(L)
*/