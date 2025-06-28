// 15. 3Sum

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Time Complexity: O(n ^ 3 * log(unique_triplets))
Space Complexity: O(unique_triplets * 2) ==> O(unique_triplets)
*/
vector<vector<int>> threeSum_Brute(vector<int> nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    // we are going to use `set` rather than `unordered_set` here because for `unordered_set` we'll need to write custom hash funtion
    set<vector<int>> s; // to store unique triplets

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());

                    if (s.find(trip) == s.end()) { // not present
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}

/*
Time Complexity: O(n ^ 2 * log(uniqueTriplets))
Space Complexity: O(uniqueTriplets + n) -> `n` is for the set
*/
vector<vector<int>> threeSum_Optimized(vector<int> nums) {
    int n = nums.size();
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        int target = -nums[i];
        set<int> s;

        for (int j = i + 1; j < n; j++) {
            int toFind = target - nums[j];

            if(s.find(toFind) != s.end()) { // found
                vector<int> trip = {nums[i], nums[j], toFind};
                sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

/*
Time Complexity: O(n.logn + n ^ 2)
Space Complexity: O(uniqueTriplets)
*/
vector<vector<int>> threeSum_TwoPointers(vector<int> nums) {
    // O(n.logn)
    sort(nums.begin(), nums.end());

    // base cases
    if (nums.size() < 3) return {};
    if (nums[0] > 0) return {};

    vector<vector<int>> ans;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        // if num[i] > 0 ==> break out as we won't find the sum as zero now
        if (nums[i] > 0) break;
        // if i is same skip this iteration
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = size - 1;
        while (left < right) {
            if (nums[left] + nums[right] + nums[i] == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});

                left++; right--;
                while(left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else if (nums[left] + nums[right] + nums[i] > 0) {
                right--;
            }
            else left++;
        }
    }
    return ans;
}

vector<vector<int>> threeSum_TwoPointers_Practice(vector<int> nums) {
    // Step 1: sort the array
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<vector<int>> ans;

    // Step 2: traverse through each index in nums
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip `i` if it's same as previous
        int j = i + 1, k = n - 1;

        // Step 3: use the two pointers approach to find triplets
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                ans.push_back({nums[i], nums[j], nums[k]});

                j++; k--;
                while (j < k && nums[j] == nums[j - 1]) j++; // skips j if same as previous
                while (j < k && nums[k] == nums[k + 1]) k--; // skips k if same as previous
            }
            else if (sum > 0) k--;
            else j++;
        }
    }

    return ans;
}


int main(void) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // 3 unique triplets which adds upto `0`
    // vector<vector<int>> res = threeSum_TwoPointers(nums);
    vector<vector<int>> res = threeSum_TwoPointers_Practice(nums);

    cout << "3 Sum Unique Triplets:\n";
    for (auto row: res) {
        cout << "{";
        for (int n: row) {
            cout << n << ", ";
        }
        cout << "\b\b}\n";
    }

    return 0;
}