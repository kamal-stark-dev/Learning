// 2596. Check Knight Tour Configuration

#include <iostream>
#include <vector>
using namespace std;

bool checkValidGrid_iterative(vector<vector<int>> grid) {
    int n = grid.size(); // n x n grid
    int row = 0, col = 0;

    if (grid[row][col] != 0) return false;

    vector<pair<int, int>> moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (int num = 1; num < n * n; num++) {
        bool foundIdx = false;

        for (auto pair : moves) {
            int newRow = row + pair.first;
            int newCol = col + pair.second;

            if (newRow >= 0 && newRow < n && newCol < n && grid[newRow][newCol] == num) {
                row = newRow;
                col = newCol;
                foundIdx = true;
                break;
            }
        }
        if (!foundIdx) return false;
    }

    return true;
}

bool checkValidGrid_recursive(vector<vector<int>> grid, int row, int col, int n, int expVal) {
    if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] != expVal) return false;

    if (expVal == n * n - 1) return true; // base case

    vector<pair<int, int>> moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (auto move : moves) {
        int newRow = row + move.first;
        int newCol = col + move.second;
        bool res = checkValidGrid_recursive(grid, newRow, newCol, n, expVal + 1);
        if (res) return true;
    }
    return false;
}

int main(void) {
    vector<vector<int>> grid = {
        {0, 11, 16,  5, 20},
        {17, 4, 19, 10, 15},
        {12, 1,  8, 21,  6},
        {3, 18, 23, 14,  9},
        {24, 13,  2, 7, 22}
    };

    // vector<vector<int>> grid = {
    //     {0, 3, 6},
    //     {5, 8, 1},
    //     {2, 7, 4}
    // };

    if(checkValidGrid_iterative(grid)) cout << "Valid\n";
    else cout << "Invalid\n";

    if(checkValidGrid_recursive(grid, 0, 0, grid.size(), 0)) cout << "Valid\n";
    else cout << "Invalid\n";

    return 0;
}