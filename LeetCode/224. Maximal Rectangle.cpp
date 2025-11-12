// 85. Maximal Rectangle

#include <iostream>
#include <vector>
using namespace std;

// TC: O(m), SC: O(m)
int largestArea(vector<int>& heights) {
    int maxArea = 0, n = heights.size();
    vector<int> left(n), right(n);
    vector<int> st;

    for (int i = 0; i < n; i++) {
        while (st.size() && heights[st.back()] >= heights[i]) {
            st.pop_back();
        }
        left[i] = st.empty() ? i + 1 : i - st.back();
        st.push_back(i);
    }

    st = {};
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() && heights[st.back()] >= heights[i]) {
            st.pop_back();
        }
        right[i] = st.empty() ? n - i : st.back() - i;
        st.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        int width = left[i] + right[i] - 1;
        maxArea = max(maxArea, width * heights[i]);
    }

    return maxArea;
}

// TC: O(n * m), SC: O(m)
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights(m, 0);

    int maximalArea = 0;
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') heights[j] += 1;
            else heights[j] = 0;
        }
        for (int h: heights) cout << h << " ";
        cout << "\n";
        int currMaximal = largestArea(heights);
        maximalArea = max(maximalArea, currMaximal);
    }
    return maximalArea;
}

int main(void) {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "The maximal rectangle is of area: " << maximalRectangle(matrix) << " sq. units\n";

    return 0;
}

/*
Time Complexity: O(n * m)
Space Complexity: O(m)
*/