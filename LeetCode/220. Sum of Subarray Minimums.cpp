// 907. Sum of Subarray Minimums

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int sumSubarrayMins_Brute(vector<int> nums) { // TC: O(n ^ 2), SC: O(1)
    const int MOD = 1e9 + 7;
    int res = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        int mini = nums[i];
        for (int j = i; j < n; j++) {
            if (nums[j] < mini) {
                mini = nums[j];
            }
            res = (res + mini) % MOD;
        }
    }
    return res;
}

int sumSubarrayMins(vector<int> nums) { // TC: O(3 * n), SC: O(2 * n)
    int n = nums.size();
    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; i++) { // O(n)
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    st = stack<int>();
    for (int i = n - 1; i >= 0; i--) { // O(n)
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    int total = 0;
    const int MOD = 1e9 + 7;

    for (int i = 0; i < n; i++) { // O(n)
        total = (total + (1LL * nums[i] * left[i] % MOD * right[i] % MOD)) % MOD; // 1LL makes turns the expression into LONG LONG and then MOD makes it under INT range
    }
    return total;
}

// extra - Sum of Subarray Maximums

int sumSubarrayMaxs(vector<int>& nums) {
    int n = nums.size(), total = 0;
    const int MOD = 1e9 + 7;

    stack<int> st;
    vector<int> left(n), right(n);

    // find left maxs
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // find right maxs
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        total = (total + (1LL * nums[i] * left[i] % MOD * right[i] % MOD)) % MOD;
    }
    return total;
}

int main(void) {
    vector<int> nums = {3, 1, 2, 4}; // 17
    // vector<int> nums = {6, 1, 2, 7, 8, 4, 5, 3, 9}; // 126

    cout << "Subarray Minimums Sum: " << sumSubarrayMins(nums) << ".\n";
    // extra
    cout << "Subarray Maxumums Sum: " << sumSubarrayMaxs(nums) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/