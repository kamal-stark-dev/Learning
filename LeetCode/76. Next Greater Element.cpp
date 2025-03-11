// 496. Next Greater Element I

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    vector<int> ans(nums1.size(), 0);

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        if (s.empty()) m[nums2[i]] = -1;
        else m[nums2[i]] = s.top();

        s.push(nums2[i]);
    }

    for (int i = 0; i < ans.size(); i++) {
        ans[i] = m[nums1[i]];
    }
    return ans;
}

int main(void) {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> nextGreater = nextGreaterElement(nums1, nums2);
    for (int n: nextGreater) cout << n << " ";
    cout << endl;

    return 0;
}
/*
m -> size of `nums2`

Time Complexity: O(m)
Space Complexity: O(m) as m > n
*/