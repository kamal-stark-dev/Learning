// Height of Binary Tree

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

int heightBT(Node* root, int height = 0) {
    if (!root) {
        return height;
    }
    return max(heightBT(root->left, height + 1), heightBT(root->right, height + 1));
}

// without the height parameter
int heightBT_2(Node* root) {
    if (!root) {
        return 0;
    }
    int leftHeight = heightBT_2(root->left);
    int rightHeight = heightBT_2(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main(void) {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "The height of the tree is " << heightBT(root) << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h), [log n <= h <= n]
*/