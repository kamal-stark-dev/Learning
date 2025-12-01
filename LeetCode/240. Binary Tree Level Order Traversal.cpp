// 102. Binary Tree Level Order Traversal

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder_BFS(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        vector<int> level;
        int qLen = q.size();
        for (int i = 0; i < qLen; i++) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (level.size()) {
            res.push_back(level);
        }
    }
    return res;
}

void DFS_helper(TreeNode* node, int depth, vector<vector<int>>& res) {
    if (!node) return;
    if (res.size() == depth) {
        res.push_back({});
    }
    res[depth].push_back(node->val);
    DFS_helper(node->left, depth + 1, res);
    DFS_helper(node->right, depth + 1, res);
}

vector<vector<int>> levelOrder_DFS(TreeNode* root) {
    vector<vector<int>> res;
    DFS_helper(root, 0, res);
    return res;
}

int main(void) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> levels = levelOrder_BFS(root);
    for (auto level: levels) {
        for (int n: level) cout << n << " ";
        cout << "\n";
    }

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n / 2) -> for the last level ~> O(n)
*/