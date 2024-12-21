// 53. Maximum Subarray
// KADANE'S ALGORITHM

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // Note: subarray is a continous part of a array

    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // cout << "The subarrays of the arr are:\n";
    // for (int start = 0; start < n; start++) {
    //     for (int end = start; end < n; end++) {
    //         cout << "{";
    //         for (int i = start; i <= end; i++) {
    //             cout << arr[i] << " ";
    //         } cout << "\b}, ";
    //     } cout << endl;
    // }

    // max subarray sum - brute force ( O(n^3) )
    /*
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    */

    // this one is O(n^2)
    /*
    int maxSum = INT_MIN;    // setting it to zero will be troublesum when all the elements are negative
    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = i; j < n; j++) {
            currSum += arr[j];
            maxSum = max(currSum, maxSum);
        }
    }
    */

    // Most optimized approach - Kadane's Algorithm
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0) // this should be after the `max` assignment because if all elements were negative it would've still given `0` if it were above.
            currSum = 0;
    }

    /*
    NOTE: I notice that when I use `nums.at(i)` instead of `nums[i]` the time taken is significantly more, and you can also use `for each` loop in vectors and it won't affect the time.
    */

    cout << "\nThe maximum sum is: " << maxSum << endl;

    return 0;
}

/*
array - {1, 2, 3, 4, 5}
subarrays - 1, 2, 3, 4, 5, 12, 23, 34, 45, 123, 234, 345, 1234, 2345, 12345
    --> there are (n * (n + 1)) / 2 subarrays for a array of size `n`, [for n = 5, subarrays = 5 * 6 / 2 = 15]
*/