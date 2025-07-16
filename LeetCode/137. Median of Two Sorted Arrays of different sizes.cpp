// Median of Two Sorted Arrays of different sizes

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedian_Brute(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;

    int i = 0, j = 0, m = nums1.size(), n = nums2.size();
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) nums.push_back(nums1[i++]);
        else nums.push_back(nums2[j++]);
    }
    while (i < m) nums.push_back(nums[i++]);
    while (j < n) nums.push_back(nums2[j++]);

    int size = m + n;
    if (size % 2 == 0) {
        int mid = size / 2;
        double median = (nums[mid] + nums[mid - 1]) / 2.0;
        return median;
    }
    else {
        return nums[size / 2];
    }
}

double findMedian_Better(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int medianIdx = (n1 + n2) / 2 + 1;
    double median, prevMedian = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2 && medianIdx) {
        if(nums1[i] < nums1[j]) {
            prevMedian = median;
            median = nums1[i];
            i++; medianIdx--;
        }
        else {
            prevMedian = median;
            median = nums2[j];
            j++; medianIdx--;
        }
    }
    while (i < n1 && medianIdx) {
        prevMedian = median;
        median = nums1[i];
        i++; medianIdx--;
    }
    while (j < n2 && medianIdx) {
        prevMedian = median;
        median = nums2[j];
        j++; medianIdx--;
    }

    if ((n1 + n2) % 2 == 0) { // even
        return (median + prevMedian) / 2.0;
    }
    return median;
}

// optimal methods is to use binary search for the same
double findMedian(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2) return findMedian(nums2, nums1);

    int leftSize = (n1 + n2 + 1) / 2; // also handles the odd lengths
    int left = 0, right = n1;
    while (left <= right) { // O(log R), R -> 0 to min(n1, n2)
        int mid1 = (left + right) / 2;
        int mid2 = leftSize - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = nums1[mid1];
        if (mid2 < n2) r2 = nums2[mid2];
        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if ((n1 + n2) % 2 == 0) {
                return (double) (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else {
                return max(l1, l2);
            }
        }
        else if (l1 > r2) right = mid1 - 1;
        else left = mid1 + 1;
    }
    return 0;
}

int main(void) {
    vector<int> nums1 = {2, 4, 6};
    vector<int> nums2 = {1, 3};

    cout << "Median of two sorted arrays is " << findMedian(nums1, nums2) << "\n";

    return 0;
}

/*
Time Complexity (Optimal): O(log min(n1, n2))
*/