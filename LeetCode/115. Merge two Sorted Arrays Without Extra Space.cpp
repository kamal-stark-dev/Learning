#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortArrays_WithSpace(vector<int>& nums1, vector<int>& nums2, int n, int m) {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) ans.push_back(nums1[i++]);
        else ans.push_back(nums2[j++]);
    }
    while (i < n) ans.push_back(nums1[i++]);
    while (j < m) ans.push_back(nums2[j++]);

    for (int i = 0; i < n + m; i++) {
        if (i < n) nums1[i] = ans[i];
        else nums2[i - n] = ans[i];
    }
}

void sortArrays_WithoutSpace(vector<int>& nums1, vector<int>& nums2, int n, int m) { // O(min(n, m)) + O(m logm) + O(n logn)
    int i = n - 1, j = 0;
    while (i >= 0 && j < m) {
        if (nums1[i] > nums2[j]) {
            swap(nums1[i], nums2[j]);
            i--; j++;
        }
        else break;
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

void sortArrays_WithoutSpace_2(vector<int>& nums1, vector<int>& nums2, int n, int m) { // O(log(n + m)) * O(n + m)
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0, right = left + gap;
        while (right < len) {
            if (left < n && right >= n) { // l in 1 and r in 2
                if (nums1[left] > nums2[right - n]) swap(nums1[left], nums2[right - n]);
            }
            else if (left >= n) { // both l and r in 2
                if (nums2[left - n] > nums2[right - n]) swap(nums2[left - n], nums2[right - n]);
            }
            else { // both l and r in 1
                if (nums1[left] > nums1[right]) swap(nums1[left], nums1[right]);
            }
            left++;
            right++;
        }
        if (gap == 1) return;
        gap = (gap / 2) + (gap % 2);
    }
}

int main(void) {
    int n = 4, m = 3;
    vector<int> nums1 = {1, 4, 8, 10};
    vector<int> nums2 = {2, 3, 9};

    sortArrays_WithoutSpace_2(nums1, nums2, n, m);
    for (int n: nums1) cout << n << " ";
    cout << '\n';
    for (int n: nums2) cout << n << " ";
    cout << '\n';

    return 0;
}