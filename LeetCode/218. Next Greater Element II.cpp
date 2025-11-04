// Next Greater Element II

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElements_Brute(vector<int> nums) { // O(n ^ 2)
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                ans[i] = nums[j];
                break;
            }
        }
        if (ans[i] == -1) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) {
                    ans[i] = nums[j];
                    break;
                }
            }
        }
    }
    return ans;
}

vector<int> nextGreaterElements(vector<int> nums) { // O(2 * n)
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;

        while (!st.empty() && st.top() <= nums[idx]) {
            st.pop();
        }
        if (i < n) {
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[idx]);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 3};

    vector<int> nextGreaters = nextGreaterElements(nums);
    for (int n: nextGreaters) cout << n << " ";

    return 0;
}

/*
Time Complexity: O(2 * n)
Space Complexity: O(n)
*/