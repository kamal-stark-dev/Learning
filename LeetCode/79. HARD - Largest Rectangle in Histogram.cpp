// 84. Largest Rectangle in Histogram

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestAreaRectangle(vector<int>& heights) {
    int maxArea = 0;
    int size = heights.size();
    stack<int> s;

    vector<int> right(size, 0);
    for (int i = size - 1; i >= 0; i--) { // O(n)
        while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
        right[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // remove any elements from the stack
    while (!s.empty()) s.pop();

    vector<int> left(size, 0); // O(n)
    for (int i = 0; i < size; i++) {
        while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    for (int i = 0; i < size; i++) { // O(n)
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