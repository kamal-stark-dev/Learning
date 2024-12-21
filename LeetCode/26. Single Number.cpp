// 136. Single Number

#include <iostream>
#include <vector>
using namespace std;

// the questions specifies to do it with linear runtime complexity
// we will use bitwise XOR, for logic refer to --> https://youtu.be/NWg38xWYzEg?si=Exxwqc_O26PzueTl&t=1807

int singleNumber(vector<int>& nums) {
    int res = 0;

    for (int num: nums) {
        res ^= num;
    }
    return res;
} // Time Coplexity: O(1)

/*
NOTE: [ num ^ num = 0 ] and [ num ^ 0 = num ]
*/

/*
There are other appraoches like -
    1. Storing frequency of each element in a map and returning the element with frequency 1. (Not constant space)
    2. Add all the unique elements in `nums` and multiply it with 2 and then subtract sum of all elements in `nums` from it.
    3. Sorting `nums` and then comparing adjacent elements.

LINk - https://leetcode.com/problems/single-number/solutions/1771720/c-easy-solutions-sorting-xor-maps-or-frequency-array/
*/

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    int singleNum = singleNumber(nums);

    cout << "Single Number: " << singleNum;

    return 0;
}