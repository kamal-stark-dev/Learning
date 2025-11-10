// 2104. Sum of Subarray Ranges

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long sumSubarrayRanges(vector<int> nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> leftMins(n), leftMaxs(n), rightMins(n), rightMaxs(n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        leftMins[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    st = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        rightMins[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    st = stack<int>();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        leftMaxs[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    st = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        rightMaxs[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += (1LL * leftMaxs[i] * rightMaxs[i] * nums[i]);
        total -= (1LL * leftMins[i] * rightMins[i] * nums[i]);
    }
    return total;
}

int main(void) {
    // vector<int> nums = {1, 2, 3}; // 4
    vector<int> nums = {1, 4, 3, 2}; // 13


    cout << "Sum of subarray ranges: " << sumSubarrayRanges(nums) << ".\n";

    return 0;
}

/*
Time Complexity: O(n) -> O(5 * n)
Space Complexity: O(n) -> O(5 * n)
*/