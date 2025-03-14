// 3356. Zero Array Transformation II

#include <iostream>
#include <vector>
using namespace std;

bool canMakeZeroArray(vector<int> nums, vector<vector<int>> queries, int k) {
    int sum = 0;
    int size = nums.size();
    vector<int> differenceArray(size + 1);

    for (int i = 0; i < k; i++) {
        int start = queries[i][0], end = queries[i][1], val = queries[i][2];

        differenceArray[start] += val;
        differenceArray[end + 1] -= val;
    }

    for (int i = 0; i < size; i++) {
        sum += differenceArray[i];
        if (sum < nums[i]) return false;
    }
    return true;
}

int minZeroArray(vector<int> nums, vector<vector<int>> queries) {
    int size = nums.size();
    int left = 0, right = queries.size();

    if (!canMakeZeroArray(nums, queries, right)) return -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canMakeZeroArray(nums, queries, mid)) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}

int main(void) {
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};

    int k = minZeroArray(nums, queries);
    cout << "You'd need at least " << k << " items from query to make a zero array.\n";

    return 0;
}
/*
It's a tricky one visit here fore details.

n -> nums.size()
m -> queries.size()

Time Complexity: O(log(m).(n + m)) -> binary search on queries (log m), in each iteration of canMakeZeroArray we go k times and then n times where k can be at max m so (n + m)

Space Complexity: O(n) -> differenceArray
*/