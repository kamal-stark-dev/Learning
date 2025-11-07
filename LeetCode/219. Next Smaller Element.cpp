// Next Smaller Element

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElements(vector<int> nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) ans[i] = st.top();
        st.push(nums[i]);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {4, 8, 5, 2, 25};

    vector<int> smallerELements = nextSmallerElements(nums); // {2, 5, 2, -1, -1}
    for (int n: smallerELements) cout << n << " ";

    return 0;
}

/*
Time Complexity: O(2 * n) -> st.pop() can go upto O(n) in worst case
Space Complexity: O(n)
*/