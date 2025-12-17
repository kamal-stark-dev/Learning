// 101. Symmetric Tree

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode { // the only difference in c++ `struct` and `class` is that struct is by `default public` and classes are not.
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// BFS Approach

bool isPalindrome(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        if (nums[l++] != nums[r--]) return false;
    }
    return true;
}

bool isSymmetric_bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int qLen = q.size();
        vector<int> level;
        for (int i = 0; i < qLen; i++) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            else {
                level.push_back(-101);
            }
        }
        // check if palindrome
        if (!isPalindrome(level)) return false;
    }
    return true;
}

// DFS Approach

bool isMirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    return (a->val == b->val) && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric_dfs(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main(void) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric_bfs(root) ? "True": "False") << "\n";
    cout << (isSymmetric_dfs(root) ? "True": "False") << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/