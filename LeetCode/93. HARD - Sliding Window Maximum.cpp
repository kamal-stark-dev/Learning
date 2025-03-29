// 239. Sliding Window Maximum

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> nums, int k) {
    int size = nums.size();

    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < k; i++) { // O(k)
        while (dq.size() > 0 && nums[dq.front()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < size; i++) { // O(n - k)
        res.push_back(nums[dq.front()]);

        // remove any out of window elements (front)
        while (dq.size() > 0 && dq.front() <= i - k) {
            dq.pop_front();
        }
        // remove the smaller values (back)
        while (dq.size() > 0 && nums[dq.front()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);
    return res;
}

int main(void) {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k); // {3, 3, 5, 5, 6, 7}
    for (int n : ans) cout << n << " ";
    cout << endl;

    return 0;
}
/*
Time Complexity: O(k) + O(n - k) ==> O(n)
Space Complexity: O(n) -> deque
*/