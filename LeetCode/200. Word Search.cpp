// 79. Word Search

#include <iostream>
#include <vector>
using namespace std;

bool check(int i, int j, int idx, vector<vector<char>>& board, string word) {
    if (idx >= word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;

    char temp = board[i][j];
    board[i][j] = '$';

    bool found = (
        check(i, j - 1, idx + 1, board, word) ||
        check(i, j + 1, idx + 1, board, word) ||
        check(i - 1, j, idx + 1, board, word) ||
        check(i + 1, j, idx + 1, board, word)
    );

    board[i][j] = temp; // backtrack

    return found;
}

// a little more optimized approach

bool exists(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();

    bool answer = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0])
                answer = check(i, j, 0, board, word);
            if (answer) return true;
        }
    }
    return false;
}

int main(void) {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    cout << (exists(board, word) ? "True": "False") << "\n";

    return 0;
}

/*
Time Complexity: O(m * n * (4 ^ L)), L -> length of the word and as we will be checking all four directions we have 4 choices
Space Complexity: O(L), the maximum recursion depth is L
*/