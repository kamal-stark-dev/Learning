// 112. Path Sum

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val_) {
        val = val_;
        left = right = nullptr;
    }
};

bool hasPathSum(Node* root, int targetSum) {
    if (!root) return false;
    targetSum -= root->val;
    if (!root->left && !root->right)
        return targetSum == 0;

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int main(void) {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    int targetSum = 22;

    cout << (hasPathSum(root, targetSum) ? "True": "False") << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h), h -> height of the tree (log n <= h <= n)
*/