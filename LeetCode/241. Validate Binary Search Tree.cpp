// 98. Validate Binary Search Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode* root, long long left, long long right) {
    if (!root) return true;
    if (root->val <= left || root->val >= right) return false;
    return (helper(root->left, left, root->val) && helper(root->right, root->val, right));
}

bool isValidBST(TreeNode* root) {
    return helper(root, LLONG_MIN, LLONG_MAX);
}

int main(void) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout << "Give tree is " << (isValidBST(root) ? "": "not ") << "a valid BST.\n";

    return 0;
}

/*
Time Complexity: O(2 * n) ~= O(n)
Space Complexity: O(n)
*/