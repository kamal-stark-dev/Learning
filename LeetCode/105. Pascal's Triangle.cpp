// 118. Pascal's Triangle

#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> generateTriangle(int rows) {
    vector<vector<int>> ans;
    for (int row = 1; row <= rows; row++) { // O(n)
        int res = 1;
        vector<int> currRow = {1};
        for (int i = 1; i < row; i++) { // O(n)
            res *= row - i;
            res /= i;
            currRow.push_back(res);
        }
        ans.push_back(currRow);
    }
    return ans;
}

void prettyPrint(vector<vector<int>> pascalTriangle, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) cout << " ";
        for (int j = 0; j <= i; j++) cout << pascalTriangle[i][j] << " ";
        cout << "\n";
    }
    return;
}

int main(void) {
    int rows = 5;
    vector<vector<int>> pascalTriangle = generateTriangle(rows);

    prettyPrint(pascalTriangle, rows);

    return 0;
}

/*
Time Complexity: O(n ^ 2)
Space Complexity: O(n ^ 2), for storing the triangle
*/