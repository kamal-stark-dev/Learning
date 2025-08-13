// Sum of Binary Tree

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

int sumBT(Node* root) {
    if (!root) return 0; // base case
    return root->val + sumBT(root->left) + sumBT(root->right);
}

int main(void) {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Sum of the binary tree is " << sumBT(root) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h), best case of balanced binary tree (h = log n) and worst case (h = n). [log n <= h <= n]
*/