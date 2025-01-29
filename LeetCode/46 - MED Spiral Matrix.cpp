// 54. Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> mat) {
    int rows = mat.size(), cols = mat[0].size();
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    vector<int> order;

    while(top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            order.push_back(mat[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            order.push_back(mat[i][right]);
        }
        right--;

        if(top <= bottom) {
            for (int i = right; i >= left; i--) {
                order.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (left == right) break;
                order.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return order;
}

int main(void) {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> spiral_matrix = spiralOrder(mat);

    cout << "Spiral Order: ";
    for (int n: spiral_matrix) cout << n << " ";
    cout << endl;

    return 0;
}

/*
Time Complexity: O(m * n)
*/