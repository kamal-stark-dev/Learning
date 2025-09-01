// Josephus Problem - https://www.geeksforgeeks.org/problems/josephus-problem/1

#include <iostream>
#include <vector>
using namespace std;

void printRemainingPerson(int n, int k, vector<int>& nums, int i = 0) {
    if (nums.size() == 1) {
        cout << nums[0] << "\n";
        return;
    }

    int idx = (i + k - 1) % nums.size();
    for (int j = idx; j < nums.size() - 1; j++) {
        nums[j] = nums[j + 1];
    }
    nums.pop_back();
    printRemainingPerson(n, k, nums, idx);
}

// recursive optimal
int josephus(int n, int k) {
    if (n == 1) return 0; // base case
    return (josephus(n - 1, k) + k) % n;
}

// iterative optimal
int josephus_iterative(int n, int k) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res + k) % i;
    }
    return res + 1; // one-indexed
}

int main(void) {
    int n = 5, k = 3;

    // vector<int> nums(n);
    // for (int i = 0 ; i < n; i++) {
    //     nums[i] = i + 1;
    // }

    // printRemainingPerson(n, k, nums);

    cout << "Last Remaining Person: " << josephus(n, k) + 1 << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n), recursion call stack
*/