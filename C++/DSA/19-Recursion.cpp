#include <iostream>
#include <vector>
using namespace std;

void printNto1(int n) {
    // base case
    if (n == 0) {
        cout << "\n";
        return;
    }

    cout << n << " ";
    printNto1(n - 1);
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
    /*
    Time Complexity: O(n) -> n calls * constant time in each cal -> O(n) * O(1)
    Space Complexity: O(n) -> n calls * constant space in each call stack -> O(n) * O(1)
    */
}

int fibonacci(int n) {
    if (n == 0 || n == 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
    /*
    Time Complexity: total calls * time for each call ==> Recursion Tree (2^0 + 2^1 + 2^2 + ... + 2^n-1) ==> (2^n - 1) * k ==> O(2 ^ n) (exponential - bad time complexity) ==> Accurate TC is O(1.618 ^ n) [Golden Ratio]

    Space Complexity: depth * memory in one stack ==> n * k ==> O(n)
    */
}

bool isSorted(vector<int> nums, int n) {
    if (n == 0 || n == 1) return true;
    return nums[n - 1] >= nums[n - 2] && isSorted(nums, n - 1);
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
}

int recBinarySearch(vector<int> nums, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return recBinarySearch(nums, target, left, mid - 1);
        else return recBinarySearch(nums, target, mid + 1, right);
    }
    return -1;
    /*
    Time Complexity: logn * k ==> O(logn)
    Space Complexity: O(logn)
    */
}

int main(void) {
    // Recursion - function calls itself again and again until base case is meet.
    printNto1(10);

    cout << "Factorial of 5: " << factorial(5) << endl;

    /*
    How do we find the time complexity in recursion ?
    -> 1. Recurrence Relation (more mathematical)
    -> 2. TC = total no. of recursion calls * work in each call (practical)

    What about space complexity ?
    -> Height of call stack * memory in each call
    */

    // Fibonacci Series
    cout << "fib(10): " << fibonacci(10) << endl;

    // Check if array is sorted - ascending
    vector<int> nums = {1, 2, 3, 4, 5};

    if (isSorted(nums, nums.size())) cout << "Array is sorted.\n";
    else cout << "Array is not sorted.\n";

    // Recursive Binary Search
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << target << " is present at index: " << recBinarySearch(arr, target, 0, arr.size() - 1) << endl;

    return 0;
}