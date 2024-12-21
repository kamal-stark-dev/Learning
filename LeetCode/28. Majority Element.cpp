// 169. Majority Element

#include <iostream>
#include <vector>
#include <algorithm> // for default sort
using namespace std;

// Brute Force - O(n^2)
int majorityElement(vector<int>& nums) {
    int size = nums.size();

    for (int i: nums) {
        int frequency = 0;
        for (int j: nums) {
            if (i == j) frequency ++;
        }
        if (frequency > (size / 2)) return i;
    }
    return -1;
}

// Little Optimized -> Sort O(nlogn) and then freq. O(n) ==> O(n.logn)
int majorityElement_Sort(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end()); // these will return the beginning and ending pointers of nums

    int freq = 1, res = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i - 1] == nums[i]) freq++;
        else {
            freq = 1;
            res = nums[i];
        }
        if (freq > size / 2) return res;
    }

    return res;
}

// Best Opproach -> Moore's Voting Algorithm ==> O(n)
int majorityElement_Moore(vector<int> nums) {
    int size = nums.size();

    int freq = 0, ans = nums[0];
    for (int i = 0; i < size; i++) {
        if (freq == 0) ans = nums[i];
        if (ans == nums[i]) freq++;
        else freq--;
    }

    return ans;
}

int main(void) {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "The majority element is: " << majorityElement_Moore(nums) << endl;

    return 0;
}