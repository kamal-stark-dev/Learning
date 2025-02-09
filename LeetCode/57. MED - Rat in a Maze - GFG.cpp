// Rat in a Maze - https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<iostream>
#include<vector>
using namespace std;

void findPaths(vector<vector<int>> maze, int row, int col, vector<string>& ans, string path) {
    int n = maze.size(); // n x n -> grid

    if (row < 0 || col < 0 || row >= n || col >= n) return;
    if (maze[row][col] == 0) return;
    if (maze[row][col] == -1) return;

    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    maze[row][col] = -1;
    // down
    findPaths(maze, row + 1, col, ans, path + "D");
    // up
    findPaths(maze, row - 1, col, ans, path + "U");
    // left
    findPaths(maze, row, col - 1, ans, path + "L");
    // right
    findPaths(maze, row, col + 1, ans, path + "R");

    maze[row][col] = 1; // backtrack
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n = maze.size();

    vector<string> paths;
    string path = "";
    findPaths(maze, 0, 0, paths, path);

    return paths;
}

int main(void) {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = ratInMaze(maze);
    for (string path : paths) {
        for (char c : path) cout << c << " ";
        cout << endl;
    }

    return 0;
}

/*
Time Complexity: we can make 4 choices for each cell and there are (n x n) cells -> O(4 ^ {n ^ 2}) | Best Case: O(n ^ 2) ~ when only one path and no backtracking is needed

Space Complexity: O(4 ^ {n ^ 2} * n ^ 2) when <visited> is used else O(4 ^ {n ^ 2}) | Auxilary Space: O(n ^ 2) ~ Recursion
*/