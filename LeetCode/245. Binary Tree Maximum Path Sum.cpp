// 124. Binary Tree Maximum Path Sum

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode* root, int& max_sum) {
    if (!root) return 0;
    int left = helper(root->left, max_sum);
    int right = helper(root->right, max_sum);
    left = max(left, 0);
    right = max(right, 0);
    max_sum = max(max_sum, root->val + left + right);
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int max_sum = root->val;
    helper(root, max_sum);
    return max_sum;
}

int main(void) {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int max_sum = maxPathSum(root);
    cout << "The maximum path sum is " << max_sum << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h), which in worst case is O(n)
*/