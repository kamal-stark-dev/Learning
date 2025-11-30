// 235. Lowest Common Ancestor of a Binary Search Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* search(TreeNode* root, int data) {
    if (!root) return nullptr;
    if (root->val == data) return root;
    TreeNode* left = search(root->left, data);
    if (left) return left;
    return search(root->right, data);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* node = root;
    while (node) {
        if (p->val < node->val && q->val < node->val) node = node->left;
        else if (p->val > node->val && q->val > node->val) node = node->right;
        else break;
    }
    return node;
}

int main(void) {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = search(root, 2);
    TreeNode* q = search(root, 8);
    TreeNode* LCA = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: " << LCA->val << "\n";

    return 0;
}

/*
Time Complexity: O()
Space Complexity: O()
*/