// 496. Next Greater Element I

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;

    for (int i = nums2.size() - 1; i >= 0; i--) { // O(n2)
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        if (s.empty()) m[nums2[i]] = -1;
        else m[nums2[i]] = s.top();

        s.push(nums2[i]);
    }

    vector<int> ans;
    for (int n: nums1) { // O(n1)
        ans.push_back(m[n]);
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
n1 -> size of nums1
n2 -> size of nums2

Time Complexity: O(n1 + n2) -> O(n1) + O(2 * n2)
Space Complexity: O(m) as m > n (and n can be m in worst case)
*/