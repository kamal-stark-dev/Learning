// 42. Trapping Rain Water

#include <iostream>
#include <vector>
using namespace std;

// prefix array approach
int trap(vector<int> heights) { // TC: O(3 * n), SC: O(2 * n)
    int size = heights.size();

    vector<int> leftMax(size);
    leftMax[0] = heights[0];
    for (int i = 1; i < size; i++) { // O(n)
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    }

    vector<int> rightMax(size);
    rightMax[size - 1] = heights[size - 1];
    for (int i = size - 2; i >= 0; i--) { // O(n)
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    }

    int trap = 0;
    for (int i = 0; i < size; i++) { // O(n)
        trap += min(leftMax[i], rightMax[i]) - heights[i];
    }

    return trap;
}

// constant space
int trap_constantSpace(vector<int> heights) { // TC: O(n), SC: O(1)
    int left = 0, right = heights.size() - 1;
    int leftMax = 0, rightMax = 0;

    int trap = 0;
    while (left < right) {
        leftMax = max(heights[left], leftMax);
        rightMax = max(heights[right], rightMax);

        if (leftMax < rightMax) {
            trap += leftMax - heights[left++];
        }
        else {
            trap += rightMax - heights[right--];
        }
    }
    return trap;
}

int main(void) {
    vector<int> heights = {4, 2, 0, 3, 2, 5};

    int trappedRainwater = trap_constantSpace(heights);
    cout << "The trapped rainwater is " << trappedRainwater << " units.\n";

    return 0;
}
/*
Time Complexity: O(n)
Space Complexity: O(3 * n) => O(n) | O(1) -> in trap_constantSpace() function.
*/