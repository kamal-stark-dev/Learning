// 104. Maximum Depth of Binary Tree

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int maxDepth_RecursiveDFS(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth_RecursiveDFS(root->left), maxDepth_RecursiveDFS(root->right));
}

int maxDepth_IterativeBFS(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        level++;
    }
    return level;
}

int maxDepth_IterativeDFS(TreeNode* root) {
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    int max_depth = 0;

    while (!st.empty()) {
        auto [node, depth] = st.top();
        st.pop();

        if (node) {
            max_depth = max(max_depth, depth);
            st.push({node->left, depth + 1});
            st.push({node->right, depth + 1});
        }
    }
    return max_depth;
}

int main(void) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "The max depth is: " << maxDepth_IterativeDFS(root) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n), ideally it's the max-depth but in worst case max-depth is n.
*/