// Distinct Values Subarray II

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countDistinctSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int count = 0, j = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        map[nums[i]]++;
        while(map.size() > k) {
            map[nums[j]]--;
            if (map[nums[j]] == 0) {
                map.erase(nums[j]);
            }
            j++;
        }
        count += i - j + 1;
    }
    return count;
}

int main(void) {
    vector<int> nums = {1, 2, 3, 1, 1};
    int k = 2; // maximum distinct elements

    cout << "The total number of distinct subarrays is " << countDistinctSubarrays(nums, k);

    return 0;
}

/*
def countDistinct(nums, k):
    map = {}
    count = 0
    j = 0
    for i in range(len(nums)):
        if nums[i] in map:
            map[nums[i]] += 1
        else:
            map[nums[i]] = 1
        while len(map) > k:
            map[nums[j]] -= 1
            if (map[nums[j]] == 0):
                map.pop(nums[j])
            j += 1
        count += i - j + 1

    return count


nums = [1, 2, 3, 1, 1]
k = 2

print(countDistinct(nums, k))
*/