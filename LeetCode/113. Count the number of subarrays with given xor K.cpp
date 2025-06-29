#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findSubarraysXORK(vector<int> nums, int k) {
    int xorr = 0, count = 0;
    unordered_map<int, int> mpp;

    mpp[xorr] += 1; // {0: 1}
    for (int n: nums) {
        xorr ^= n;
        count += mpp[k ^ xorr];
        mpp[xorr] += 1;
    }
    for (auto it: mpp) {
        cout << it.first << "->" << it.second << "\n";
    }
    return count;
}

int main(void) {
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    int count = findSubarraysXORK(nums, k);

    cout << "There are " << count << " subarrays in the array that xor upto K.\n";
    return 0;
}