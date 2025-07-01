// 152. Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

int findMaxProduct_Brute(const vector<int>& nums) { // O(n ** 2)
    int n = nums.size();
    int maxProduct = INT_MIN;

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = i; j < n; j++) {
            product *= nums[j];
            maxProduct = max(maxProduct, product);
        }
    }
    return maxProduct;
}

int findMaxProduct_Optimal_1(const vector<int>& nums) { // O(n)
    int n = nums.size();
    int maxProduct = INT_MIN;
    int prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++) {
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;
        prefix *= nums[i];
        suffix *= nums[n - i - 1];
        maxProduct = max({maxProduct, prefix, suffix});
    }
    return maxProduct;
}

int findMaxProduct_Optimal_2(const vector<int>& nums) { // O(2 * n) -> exactly the same as above just wrote differently
    int n = nums.size();
    int maxProduct = INT_MIN;
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= nums[i];
        maxProduct = max(maxProduct, product);
        if (product == 0) product = 1;
    }
    product = 1;
    for (int i = n - 1; i >= 0; i--) {
        product *= nums[i];
        maxProduct = max(maxProduct, product);
        if (product == 0) product = 1;
    }
    return maxProduct;
}

int main(void) {
    vector<int> nums = {2, 3, -2, 4, -1, 0, -3, -4, 5, -6};
    int maxProduct = findMaxProduct_Optimal_2(nums);

    cout << "Maximum Product: " << maxProduct << '\n';
    return 0;
}