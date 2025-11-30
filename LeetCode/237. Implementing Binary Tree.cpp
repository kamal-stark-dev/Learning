// Implementing Binary Tree

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>
#include <queue>
using namespace std;

bool getRandomMove() {
    return rand() % 2;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode *root;

    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    void displayHelper(TreeNode* root) {
        if (!root) return;
        displayHelper(root->left);
        cout << root->val << " ";
        displayHelper(root->right);
    }

    TreeNode* searchHelper(TreeNode* root, int data) {
        if (!root) return nullptr;
        if (root->val == data) return root;

        TreeNode* left = searchHelper(root->left, data);
        if (left) return left;

        return searchHelper(root->right, data);
    }
public:
    // constructor
    BinaryTree(): root(nullptr) {}

    // destructor
    ~BinaryTree() {
        destroy(root);
    }

    void insertNode(int data) {
        if (!root) {
            root = new TreeNode(data);
            return;
        }
        // as there is no specific order to insert in a binary tree -> I'll move randomly till we get a leaf node
        TreeNode* temp = root;
        while (temp->left != nullptr && temp->right != nullptr) {
            if (getRandomMove())
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (temp->left == nullptr) temp->left = new TreeNode(data);
        else temp->right = new TreeNode(data);
    }

    void display() {
        displayHelper(root);
        cout << "\n";
    }

    void levelOrderDisplay() {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr) {
                cout << curr->val << " ";
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        cout << "\n";
    }

    TreeNode* searchNode(int data) {
        return searchHelper(root, data);
    }

    void deleteNode(int data) {
        if (!root) return;
        if (!root->left && !root->right && root->val == data) {
            delete root;
            root = nullptr;
            return;
        }

        TreeNode* nodeToDelete = nullptr;
        TreeNode* last = nullptr;
        TreeNode* parentOfLast = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            if (curr->val == data) {
                nodeToDelete = curr;
            }
            if (curr->left) {
                parentOfLast = curr;
                last = curr->left;
                q.push(curr->left);
            }
            if (curr->right) {
                parentOfLast = curr;
                last = curr->right;
                q.push(curr->right);
            }
        }

        if (!nodeToDelete) return;

        if (last) {
            nodeToDelete->val = last->val;

            if (parentOfLast->left == last) {
                parentOfLast->left = nullptr;
            }
            else {
                parentOfLast->right = nullptr;
            }
            delete last;
        }
    }
};

int main(void) {
    // random seed
    srand(static_cast<unsigned int>(time(0)));

    // Binary Tree
    BinaryTree bt;

    // insertion
    bt.insertNode(4);
    bt.insertNode(1);
    bt.insertNode(2);
    bt.insertNode(3);
    bt.insertNode(5);
    bt.insertNode(8);

    // display
    bt.display();

    // searching
    cout << ((bt.searchNode(3) != nullptr) ? "true": "false") << "\n";
    cout << ((bt.searchNode(10) != nullptr) ? "true": "false") << "\n";

    // deletion
    bt.deleteNode(2);
    bt.deleteNode(8);

    bt.display();

    // level order traversal
    bt.levelOrderDisplay();

    return 0;
}

/*
Time Complexity:
    - insertNode: O(h) average, O(n) worst
    - searchNode: O(n)
    - deleteNode: O(n)
    - display   : O(n)

Space Complexity:
    - deleteNode: O(n) (queue)
    - recursion-based-functions: O(h) call stack
*/