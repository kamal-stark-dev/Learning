// 297. Serialize and Deserialize Binary Tree

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// DFS - Depth First Search
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

// BFS - Breadth First Search
string serialize_bfs(TreeNode* root) {
    string s = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            s += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        else {
            s += "N,";
        }
    }
    s.pop_back();
    return s;
}

TreeNode* deserialize_bfs(string data) {
    vector<string> nodes;
    string node;
    for (char c: data) {
        if (c == ',') {
            nodes.push_back(node);
            node = "";
        }
        else node += c;
    }
    if (node.size()) nodes.push_back(node);

    if (nodes[0] == "N") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (nodes[index] != "N") {
            node->left = new TreeNode(stoi(nodes[index]));
            q.push(node->left);
        }
        index++;
        if (nodes[index] != "N") {
            node->right = new TreeNode(stoi(nodes[index]));
            q.push(node->right);
        }
        index++;
    }
    return root;
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

    string serialized = serialize_bfs(root);
    TreeNode* deserialized = deserialize_bfs(serialized);

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