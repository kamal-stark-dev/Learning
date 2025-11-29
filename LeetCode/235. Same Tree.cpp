// 100. Same Tree

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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;

    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSameTree_iterativeBFS(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*, TreeNode*>> queue;
    queue.push({p, q});

    while (!queue.empty()) {
        auto [node1, node2] = queue.front();
        queue.pop();

        if (!node1 && !node2) continue;
        if (!node1 || !node2 || node1->val != node2->val) return false;
        queue.push({node1->left, node2->left});
        queue.push({node1->right, node2->right});
    }
    return true;
}

bool isSameTree_iterativeDFS(TreeNode*p, TreeNode* q) {
    stack<pair<TreeNode*, TreeNode*>> st;
    st.push({p, q});

    while (!st.empty()) {
        auto [node1, node2] = st.top(); st.pop();

        if (!node1 && !node2) continue;
        if (!node1 || !node2 || node1->val != node2->val) return false;
        st.push({node1->left, node2->left});
        st.push({node1->right, node2->right});
    }
    return true;
}

int main(void) {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "Both trees are " << (isSameTree_iterativeDFS(root1, root2) ? "": "not ") << "same.\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n), due to worst case of unbalanced tree to one side
*/