// 108. Convert Sorted Array to Binary Search Tree

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* dfs(int left, int right, const vector<int>& nums) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = dfs(left, mid - 1, nums);
    node->right = dfs(mid + 1, right, nums);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(0, nums.size() - 1, nums);
}

void display(TreeNode* node) {
    if (!node) {
        // cout << "null ";
        return;
    }

    cout << node->val << " ";
    display(node->left);
    display(node->right);
}

int main(void) {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    display(root);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for tree nodes and O(log n) for recursion stack (as its height-balanced tree)
*/