// Celebrity Problem

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Given a 2D array (n x n), such that arr[i][j] = 1 means that the ith person knows the jth person.
The task is to find the celebrity, a person who is known to all but doesn't know anybody, return the index of celeb or -1 is not any.
*/

int celebrity(vector<vector<int>> nums) {
    stack<int> s;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    int i, j;
    while (s.size() >= 2) {
        i = s.top();
        s.pop();
        j = s.top();
        s.pop();

        if (nums[i][j] == 0) {
            s.push(i);
        }
        else {
            s.push(j);
        }
    }

    int celeb = s.top();
    for (int i = 0; i < n; i++) {
        if (i != celeb && (nums[i][celeb] == 0 || nums[celeb][i] == 1)) return -1;
    }
    return celeb;
}

int main(void) {
    vector<vector<int>> nums = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    cout << "Celebrity is: " << celebrity(nums) << endl;

    return 0;
}
/*
Time Complexity: O(3 * n) => O(n)
Space Complexity: O(n) -> stack
*/