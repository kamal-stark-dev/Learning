// 297. Serialize and Deserialize Binary Tree

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void serialize_helper(TreeNode* node, string& s) {
    if (!node) {
        s += "N,";
        return;
    }
    string value = to_string(node->val);
    s += value + ",";
    serialize_helper(node->left, s);
    serialize_helper(node->right, s);
}

string serialize(TreeNode* root) { // TC: O(n), SC: O(h)
    string s = "";
    serialize_helper(root, s);
    s.pop_back(); // remove the last comma
    return s;
}

TreeNode* deserialize_helper(const vector<string>& nodes, int& idx) {
    if (nodes[idx] == "N") {
        idx++;
        return nullptr;
    }
    int node_val = stoi(nodes[idx]);
    idx++;
    TreeNode* node = new TreeNode(node_val);
    node->left = deserialize_helper(nodes, idx);
    node->right = deserialize_helper(nodes, idx);
    return node;
}

TreeNode* deserialize(string data) { // TC: O(n), SC: O(h)
    vector<string> nodes;
    string node;
    for (char c: data) {
        if (c == ',') {
            nodes.push_back(node);
            node = "";
        }
        else {
            node += c;
        }
    }
    if (node.size()) nodes.push_back(node);
    int idx = 0;
    return deserialize_helper(nodes, idx);
}

void display(TreeNode* node) {
    if (!node) return;
    display(node->left);
    cout << node->val << " ";
    display(node->right);
}

int main(void) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = serialize(root);
    TreeNode* deserialized = deserialize(serialized);

    display(deserialized);

    return 0;
}

/*
Time Complexity:
    - Serialize: O(n)
    - Deserialize: O(n)
Space Complexity:
    - Serialize: O(n)
    - Deserialize: O(n), nodes
*/