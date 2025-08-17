// Minimum Height of Binary Tree

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;

    Node(int val_) {
        val = val_;
        left = right = nullptr;
    }
};

int minHeightBT(Node* root) {
    if (!root) return 0;
    int leftHeight = minHeightBT(root->left);
    int rightHeight = minHeightBT(root->right);

    if (leftHeight == 0) return 1 + rightHeight;
    if (rightHeight == 0) return 1 + leftHeight;
    return 1 + min(leftHeight, rightHeight);
}

int main(void) {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "The minimum height of the tree is " << minHeightBT(root) << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h), [log n <= h <= n]
*/