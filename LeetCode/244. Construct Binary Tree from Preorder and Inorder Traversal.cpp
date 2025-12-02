// 244. Construct Binary Tree from Preorder and Inorder Traversal

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& preorder, int& preIndex, int left, int right, unordered_map<int, int>& map) {
    if (left > right) return nullptr;

    int root_val = preorder[preIndex];
    preIndex += 1;
    TreeNode* root = new TreeNode(root_val);

    int mid = map[root_val];

    root->left = build(preorder, preIndex, left, mid - 1, map);
    root->right = build(preorder, preIndex, mid + 1, right, map);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); i++) {
        map[inorder[i]] = i;
    }
    int preIndex = 0;
    return build(preorder, preIndex, 0, inorder.size() - 1, map);
}

void display(TreeNode* root) {
    if (!root) return;
    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main(void) {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);
    display(root);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n), in avg. case it takes O(h=logn), in worst case O(n)
*/