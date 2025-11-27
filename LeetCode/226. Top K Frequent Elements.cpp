// 347. Top K Frequent Elements

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent_Sorting(vector<int> nums, int k) { // TC: O(n logn), SC: O(n)
    unordered_map<int, int> map;
    for (int n: nums) map[n]++;

    vector<pair<int, int>> freq;
    for (auto p: map) {
        freq.push_back({p.second, p.first});
    }
    sort(freq.rbegin(), freq.rend());

    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(freq[i].second);
    }
    return res;
}

vector<int> topKFrequent_MinHeap(vector<int> nums, int k) { // TC: O(n logk), SC: O(n)
    unordered_map<int, int> count;
    for (int n: nums) count[n]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for (auto& entry: count) {
        heap.push({entry.second, entry.first}); // O(n)
        if (heap.size() > k) heap.pop(); // O(logk)
    }

    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(heap.top().second);
        heap.pop();
    }
    return res;
}

vector<int> topKFrequent_BucketSort(vector<int> nums, int k) { // TC: O(n), SC: O(n)
    unordered_map<int, int> map;
    for (int n: nums) {
        map[n]++;
    }

    vector<vector<int>> freq(nums.size() + 1);
    for (auto p: map) {
        freq[p.second].push_back(p.first);
    }

    vector<int> res;
    for (int i = nums.size(); i >= 0; i--) {
        for (int n: freq[i]) {
            res.push_back(n);
            if (res.size() == k) return res;
        }
    }
    return res;
}

int main(void) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> res = topKFrequent_BucketSort(nums, k);
    for (int n: res) {
        cout << n << " ";
    }
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/