#include <iostream>
#include <vector>
using namespace std;

void printSpiralMatrix(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            cout << mat[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << mat[i][right] << " ";
        }
        right--;

        if (top <= bottom) {

            for (int i = right; i >= left; i--) {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right) {

            for (int i = bottom; i >= top; i--) {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
}

int main(void) {
    // vector<vector<int>> mat = {
    //     {  1,  2,  3,  4 },
    //     {  5,  6,  7,  8 },
    //     {  9, 10, 11, 12 },
    //     { 13, 14, 15, 16 }
    // };

    vector<vector<int>> mat = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    printSpiralMatrix(mat);
    return 0;
}