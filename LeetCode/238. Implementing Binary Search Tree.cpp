// Implementing Binary Search Tree

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    TreeNode* insertHelper(TreeNode* root, TreeNode* node) {
        if (!root) {
            root = node;
            return root;
        }
        else if (node->val < root->val) {
            root->left = insertHelper(root->left, node);
        }
        else {
            root->right = insertHelper(root->right, node);
        }
        return root;
    }

    void displayHelper(TreeNode* node) {
        if (!node) return;
        displayHelper(node->left);
        cout << node->val << " ";
        displayHelper(node->right);
    }

    TreeNode* searchHelper(TreeNode* node, int data) {
        if (!node) return nullptr;
        if (node->val == data) return node;

        if (data < node->val) {
            return searchHelper(node->left, data);
        }
        return searchHelper(node->right, data);
    }

    int successor(TreeNode* root) {
        TreeNode* node = root->right;
        while (node->left) {
            node = node->left;
        }
        return node->val;
    }

    int predecessor(TreeNode* root) {
        TreeNode* node = root->left;
        while (node->right) {
            node = node->right;
        }
        return node->val;
    }

    TreeNode* removeHelper(TreeNode* node, int data) {
        if (!node) return nullptr;
        if (data < node->val) {
            node->left = removeHelper(node->left, data);
        }
        else if (data > node->val) {
            node->right = removeHelper(node->right, data);
        }
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if (node->right) {
                node->val = successor(node);
                node->right = removeHelper(node->right, node->val);
            }
            else {
                node->val = predecessor(node);
                node->left = removeHelper(node->left, node->val);
            }
        }
        return node;
    }
public:
    BST(): root(nullptr) {}

    ~BST() {
        destroy(root);
    }

    void insert(int data) {
        // TreeNode* node = new TreeNode(data);
        // root = insertHelper(root, node);

        if (!root) {
            root = new TreeNode(data);
            return;
        }

        TreeNode* node = root;
        while (node) {
            if (data < node->val) {
                if (!node->left) {
                    node->left = new TreeNode(data);
                    return;
                }
                node = node->left;
            }
            else {
                if (!node->right) {
                    node->right = new TreeNode(data);
                    return;
                }
                node = node->right;
            }
        }
    }

    TreeNode* search(int data) {
        return searchHelper(root, data);
    }

    void displayDFS() {
        displayHelper(root);
        cout << "\n";
    }

    void remove(int data) {
        root = removeHelper(root, data);
    }

    void displayBFS() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n";
    }
};

int main(void) {
    BST bt;

    bt.insert(2);
    bt.insert(4);
    bt.insert(6);
    bt.insert(3);
    bt.insert(1);

    bt.displayDFS();

    cout << (bt.search(5) == nullptr ? "false": "true") << "\n";
    cout << (bt.search(6) == nullptr ? "false": "true") << "\n";

    bt.remove(4);

    bt.displayBFS();

    return 0;
}

/*
Time Complexity:
    - insert: O(logn)
    - remove: O(logn) -> maybe a little extra for successor and predecessor but still propotional to height
    - search: O(logn)
    - display (DFS and BFS): O(n)
Space Complexity:
    - in avg. case of a 'nice' tree: O(h) ~= O(logn)
    - in worst case: O(n)
*/