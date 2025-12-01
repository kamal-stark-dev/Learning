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

void morrisInorderTraversal(TreeNode* root) { // left -> root -> right
    cout << "Inorder: ";
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
    cout << "\n";
}

void morrisPreorderTraversal(TreeNode* root) { // root -> left -> right
    cout << "Preorder: ";
    TreeNode* curr = root;
    while (curr) {
        if (!curr->left) {
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
                cout << curr->val << " ";
                curr = curr->left;
            }
            else {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    cout << "\n";
}

// Morris Postorder is like the final boss, so let's skip it :)

int main(void) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    morrisInorderTraversal(root);
    morrisPreorderTraversal(root);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1) -> the main difference
*/