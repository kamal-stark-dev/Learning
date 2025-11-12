// 84. Largest Rectangle in Histogram

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestAreaRectangle(vector<int>& heights) {
    int maxArea = 0;
    int n = heights.size();

    stack<int> st;
    vector<int> right(n), left(n);

    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        right[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop(); // st = stack<int>();

    for (int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        maxArea = max(currArea, maxArea);
    }
    return maxArea;
}

int main(void) {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int maxArea = largestAreaRectangle(heights);
    cout << "The maximum area in the histogram is: " << maxArea << endl;

    return 0;
}
/*
Time Complexity: O(n)
Space Complexity: O(n) -> stack, left and right
*/