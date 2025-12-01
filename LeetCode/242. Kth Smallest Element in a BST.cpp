// 230. Kth Smallest Element in a BST

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node, vector<int>& res) {
    if (!node) return;
    dfs(node->left, res);
    res.push_back(node->val);
    dfs(node->right, res);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    dfs(root, res);
    return res[k - 1];
}

int kthSmallest_iterative(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    int smallCount = 0;

    while (!st.empty() || curr) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        smallCount++;
        if (k == smallCount) return curr->val;
        curr = curr->right;
    }
    return -1; // will never execute
}

int main(void) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 3;
    cout << k << "(th) smallest element in BST: " << kthSmallest_iterative(root, k);

    return 0;
}

/*
Time Complexity: O()
Space Complexity: O()
*/