// Quick Sort - Pivot & Partition

#include <iostream>
#include <vector>
using namespace std;

/*
1. Pick the pivot
2. Partition [<= elements] pivot [> elements] --> puts the pivot to its correct position
3. Do the same for the left and right sides
*/

int partition(vector<int>& nums, int start, int end) {
    int i = start - 1, pivot = nums[end];

    for (int j = start; j < end; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[j], nums[i]);
        }
    }
    i++;
    swap(nums[end], nums[i]); // placing pivot to correct position
    return i;
}

void quickSort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int pvtIdx = partition(nums, start, end);

        quickSort(nums, start, pvtIdx - 1); // left half
        quickSort(nums, pvtIdx + 1, end); // right half
    }
}

vector<int> quickSort_2(vector<int> nums) {
    if (nums.size() <= 1) return nums;

    int pivot = nums[0]; // chossing the first element as pivot
    vector<int> left, right;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= pivot) left.push_back(nums[i]);
        else right.push_back(nums[i]);
    }

    // recursive calling
    left = quickSort_2(left);
    right = quickSort_2(right);

    vector<int> sorted;
    sorted.insert(sorted.end(), left.begin(), left.end());
    sorted.push_back(pivot);
    sorted.insert(sorted.end(), right.begin(), right.end());
    return sorted;
}

void printArray(vector<int> nums) {
    for (int n: nums) {
        cout << n << " ";
    }
    cout << endl;
}

int main(void) {
    vector<int> nums = {5, 2, 6, 4, 1, 3};
    quickSort(nums, 0, nums.size() - 1);
    printArray(nums);

    vector<int> sorted = quickSort_2(nums);
    printArray(sorted);

    return 0;
}
/*
Time Complexity: O(n log.g) in average cases, O(n^2) in worst case (occurs when pivot is repeatedly the smallest or the largest element)
Space Complexity: O(1)

As "Quick Sort" takes constant space, it's preferred over "Merge Sort" even though it can be O(n^2) sometimes.
*/