// 268. Missing Number

#include <iostream>
#include <vector>
using namespace std;

int findMissing_Brute(vector<int> nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) flag = true;
        }
        if (!flag) return i;
    }
    return n;
}

int findMissing_Better(vector<int> nums) {
    int n = nums.size();
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        freq[nums[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (freq[i] == 0) return i;
    }
    return n;
}

int findMissing_Optimal(vector<int> nums) {
    int n = nums.size();

    int sum = 0;
    for (int num: nums) sum += num;
    int nSum = (n * (n + 1)) / 2;

    return nSum - sum;
}

int main(void) {
    vector<int> nums = {3, 0, 1};

    int missingNumber = findMissing_Optimal(nums);

    cout << "The missing number is " << missingNumber << endl;

    return 0;
}

/*
Time Complexity:
    Brute: O(n * n)
    Better: O(2 * n)
    Optimal: O(n)

Space Complexity:
    Brute: O(1)
    Better: O(n)
    Optimal: O(1)
*/