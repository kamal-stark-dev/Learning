// 200. Number of Islands

#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<bool>>& visited, const vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == '0') return;

    visited[r][c] = true;
    dfs(r + 1, c, visited, grid);
    dfs(r - 1, c, visited, grid);
    dfs(r, c + 1, visited, grid);
    dfs(r, c - 1, visited, grid);
}

int numIslands(const vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int islands = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1' && visited[r][c] == false) {
                islands++;
                dfs(r, c, visited, grid);
            }
        }
    }
    return islands;
}

int main(void) {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    int islands = numIslands(grid);
    cout << "There are " << islands << " island(s) in the area.\n";

    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/