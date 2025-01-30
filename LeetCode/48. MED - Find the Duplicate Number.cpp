// 287. Find the Duplicate Number

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> nums) {
    int slow = nums[0], fast = nums[0];

    do {
        slow = nums[slow]; // + 1
        fast = nums[nums[fast]]; // + 2
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow]; // + 1
        fast = nums[fast]; // + 1
    }
    return fast;
}

int main(void) {
    vector<int> nums = {1, 3, 4, 2, 2}; // 2 is duplicate
    cout << "Duplicate: " << findDuplicate(nums) << endl;

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)

if we use `hashing(unordered_set)` approach we'll have Space Complexity of O(n).

DRY RUN -
nums = {1, 3, 4, 2, 2}
        0  1  2  3  4
slow = a[0], fast = a[0]
slow = 1, fast = 1

slow = a[slow] = a[1] = 3
fast = a[a[fast]] = a[a[1]] = a[3] = 2

slow != fast
slow = a[slow] = a[3] = 2
fast = a[a[fast]] = a[a[2]] = a[4] = 2

slow == fast; exit do while loop

slow = a[0] = 1
fast = 2

while slow != fast

slow = a[slow] = a[1] = 3
fast = a[fast] = a[2] = 4

slow = a[slow] = a[3] = 2
fast = a[fast] = a[4] = 4

as fast == slow; break

return fast or slow

ans: 2
*/