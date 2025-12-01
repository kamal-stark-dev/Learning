// Morris Traversal in Binary Tree
// it uses the concept of `threaded binary tree` in which the leaf nodes point to their root in their respective subtrees

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void morrisInorderTraversal(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (!curr->left) {
            // display root
            cout << curr->val << " ";
            curr = curr->right;
        }
        else {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if (!prev->right) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

int main(void) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    morrisInorderTraversal(root);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1) -> the main difference
*/