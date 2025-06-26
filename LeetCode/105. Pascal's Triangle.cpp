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

int pascalRowColValue(int row, int col) {
    // 5, 3 -> nCr where n = row - 1, and r = col - 1
    int n = row - 1, r = col - 1;
    int res = 1;
    for (int i = 1; i <= r; i++) {
        res *= (n - i + 1); // as i starts from 1
        res /= i;
    }
    return res;
}

vector<int> pascalRow(int row) {
    // for n-th row there will be n elements.
    vector<int> prow = {1};
    for (int i = 2; i <= row; i++) {
        prow.push_back(pascalRowColValue(row, i));
    }
    return prow;
}

vector<vector<int>> PascalTriangle(int rows) { // O(r ^ 2) => r is row_count
    vector<vector<int>> triangle;
    for (int i = 1; i <= rows; i++) {
        triangle.push_back(pascalRow(i));
    }
    return triangle;
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
    // vector<vector<int>> pascalTriangle = generateTriangle(rows);

    cout << "Pascal[1][1]: " << pascalRowColValue(0, 0) << '\n';
    cout << "Pascal[5][3]: " << pascalRowColValue(5, 3) << '\n';

    vector<int> prow = pascalRow(5);

    cout << "\nRow 5 of Pascal Triangle: \n";
    for (int n: prow) cout << n << " ";

    cout << "\n\nPascal Triangle with " << rows << " rows:\n";
    vector<vector<int>> pascalTriangle = PascalTriangle(rows);
    prettyPrint(pascalTriangle, rows);

    return 0;
}

/*
Time Complexity: O(n ^ 2)
Space Complexity: O(n ^ 2), for storing the triangle
*/