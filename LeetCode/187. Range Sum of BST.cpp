// 938. Range Sum of BST

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

void helper(Node* root, int low, int high, int& sum) {
    if (!root) return;
    if (root->val >= low && root->val <= high) sum += root->val;

    helper(root->left, low, high, sum);
    helper(root->right, low, high, sum);
}

int rangeSumBST(Node* root, int low, int high) {
    int sum = 0;
    helper(root, low, high, sum);
    return sum;
}

// Another Way

int rangeSumBST_2(Node* root, int low, int high) {
    if (!root) return 0;
    if (root->val >= low && root->val <= high) {
        return root->val + rangeSumBST_2(root->left, low, high) + rangeSumBST_2(root->right, low, high);
    }
    return rangeSumBST_2(root->left, low, high) + rangeSumBST_2(root->right, low, high);
}

// Most Optimal Way - Pruning

int rangeSumBST_Pruning(Node* root, int low, int high) {
    if (!root) return 0;
    if (root->val < low) {
        // prune the left subtree
        return rangeSumBST_Pruning(root->right, low, high);
    }
    if (root->val > high) {
        // prune the right subtree
        return rangeSumBST_Pruning(root->left, low, high);
    }

    return root->val + rangeSumBST_Pruning(root->left, low, high) + rangeSumBST_Pruning(root->right, low, high);
}

int main(void) {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int low = 7, high = 15;

    cout << "The range sum is " << rangeSumBST_Pruning(root, low, high) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h), h -> height of the tree (log n <= h <= n)
*/