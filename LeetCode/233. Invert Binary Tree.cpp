// 226. Invert Binary Tree

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertNode(TreeNode* root) {
    if (!root) return nullptr;

    swap(root->left, root->right);

    invertNode(root->left);
    invertNode(root->right);
    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
        // else {
        //     cout << "null ";
        // }
    }
    cout << endl;
}

int main(void) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original Tree (Level Order): ";
    printLevelOrder(root);

    root = invertNode(root);

    cout << "Inverted Tree (Level Order): ";
    printLevelOrder(root);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n), for recursion stack in worst case
*/