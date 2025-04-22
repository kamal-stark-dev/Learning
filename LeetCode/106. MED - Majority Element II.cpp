// 229. Majority Element II

#include <vector>
#include <iostream>
using namespace std;

vector<int> majorityElement(vector<int> nums) {
    int cnt1 = 0, cnt2 = 0;
    int el1, el2, size = nums.size();

    for (int i = 0; i < size; i++) {
        if (nums[i] == el1) cnt1++;
        else if (nums[i] == el2) cnt2++;
        else if (cnt1 == 0 && nums[i] != el2) {
            el1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && nums[i] != el1) {
            el2 = nums[i];
            cnt2 = 1;
        }
        else {
            cnt1--; cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }

    vector<int> res;
    if (cnt1 > size / 3) res.push_back(el1);
    if (cnt2 > size / 3) res.push_back(el2);
    return res;
}

int main(void) {
    vector<int> nums = {3,2,3};
    vector<int> majors = majorityElement(nums);

    for (int n: majors) cout << n << " ";
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(2 * n)
Space Complexity: O(1)
*/