// 503. Next Greater Element II

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int> nums) {
    stack<int> s;
    int size = nums.size();
    vector<int> ans (size, -1);

    for (int i = 2 * size - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] <= nums[i % size]) s.pop();
        ans[i % size] = s.empty() ? -1 : nums[s.top()];
        s.push(i % size); // push the idx in stack
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> nextGreaters = nextGreaterElements(nums);

    for (int n : nextGreaters) cout << n << " ";
    return 0;
}
/*
Time Complexity: O(2 * n) -> O(n)
Space Complexity: O(2 * n) -> O(n)
*/