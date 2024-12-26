// 11. Container With Most Water - https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
using namespace std;

// This apprach takes quadratic time complexity - O(n^2)
int maxArea_brute(vector<int> heights) {
    int size = heights.size();

    int maxArea = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int width = j - i;
            int height = min(heights[i], heights[j]);

            maxArea = max(maxArea, height * width);
        }
    }
    return maxArea;
}

// Optimized approach -> 2 pointer approach
int maxArea_2Ptrs(vector<int> heights) {
    int size = heights.size(), maxArea = 0;

    int left = 0, right = size - 1;

    while (left < right) {
        int width = right - left;
        int height = min(heights[left], heights[right]);
        int currArea = width * height;

        maxArea = max(maxArea, currArea);

        // if (heights[left] <= heights[right]) left++;
        // else right--;
        (heights[left] < heights[right]) ? left++ : right--;
    }
    return maxArea;
}
/*
Time Complexity -> if `left` ptr travels `d` distance then `right` would travel `(n - d)` distance, d + (n - d) = n ==> O(n)
*/

int main() {

    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "The max area is: " << maxArea_2Ptrs(heights);

}