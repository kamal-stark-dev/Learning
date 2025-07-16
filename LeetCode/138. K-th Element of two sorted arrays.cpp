// K-th Element of two sorted arrays

#include <iostream>
#include <vector>
using namespace std;

// Brute - Create a merged array and return its k-th element
// Better - Use the two pointer approach to find k-th element

// My take before looking at the solution, I was misunderstanding the partition (was thinking it's cut in exact halves only)
int kthElement_MyTake(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2) return kthElement_MyTake(nums2, nums1, k);

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
            int element = -1;
            if (k <= leftSize) {
                int i = 0, j = 0;
                while (i <= (mid1 - 1) && j <= (mid2 - 1) && k) {
                    if (nums1[i] < nums2[j]) element = nums1[i++];
                    else element = nums2[j++];
                    k--;
                }
                while (i <= l1 && k) {
                    element = nums1[i++];
                    k--;
                }
                while (j <= l2 && k) {
                    element = nums2[j++];
                    k--;
                }
            }
            else {
                k -= leftSize;
                int i = mid1, j = mid2;
                while (i < n1 && j < n2 && k) {
                    if (nums1[i] < nums2[j]) element = nums1[i++];
                    else element = nums2[j++];
                    k--;
                }
                while (i < n1 && k) {
                    element = nums1[i++];
                    k--;
                }
                while (j < n2 && k) {
                    element = nums2[j++];
                    k--;
                }
            }
            return element;
        }
        else if (l1 > r2) right = mid1 - 1;
        else left = mid1 + 1;
    }
    return 0;
}

int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2) return kthElement(nums2, nums1, k);

    int leftSize = k;
    int left = max(0, n2 - k), right = min(k, n1); // think about the why these ranges
    while (left <= right) {
        int mid1 = (left + right) / 2;
        int mid2 = leftSize - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) right = mid1 - 1;
        else left = mid1 + 1;
    }
    return 0;
}

int main(void) {
    vector<int> nums1 = {2, 3, 6, 15};
    vector<int> nums2 = {1, 4, 7, 10, 12};
    int k = 7;

    cout << "K-th(" << k << ") element of given sorted arrays is " << kthElement(nums1, nums2, k) << "\n";

    return 0;
}

/*
Time Complexity: O(log min(n1, n2))
*/