#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> mergeOverlappingIntervals(vector<pair<int, int>> nums) {
    int n = nums.size();
    if (n <= 1) return nums;

    sort(nums.begin(), nums.end());
    vector<pair<int, int>> ans;

    int start = nums[0].first, end = nums[0].second;
    int i = 1;
    while (i < n) {
        while (i < n && nums[i].first <= end) {
            end = max(end, nums[i].second);
            i++;
        }
        ans.push_back({start, end});
        if (i == n) break;
        start = nums[i].first;
        end = nums[i].second;
    }
    return ans;
}

int main(void) {
    vector<pair<int, int>> nums = {{1, 3}, {12, 15}, {8, 10}, {2, 6}};
    // vector<pair<int, int>> nums = {{1, 4}, {2, 3}, {4, 7}, {6, 10}, {12, 15}};
    vector<pair<int, int>> merged = mergeOverlappingIntervals(nums);

    cout << "{";
    for (auto p: merged) {
        cout << "{" << p.first << ", " << p.second << "}, ";
    }
    cout << "\b\b}\n";
}