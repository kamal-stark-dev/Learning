// 133. Clone Graph

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* createGraphFromAdjList(const vector<vector<int>>& adjList) {
    if (adjList.empty()) return nullptr;

    unordered_map<int, Node*> nodes_map;
    for (int i = 0; i < adjList.size(); i++) {
        int node_val = i + 1;
        nodes_map[node_val] = new Node(node_val);
    }

    for (int i = 0; i < adjList.size(); i++) {
        int node_val = i + 1;
        Node* curr_node = nodes_map[node_val];
        for (int neighbor_val: adjList[i]) {
            if (nodes_map.count(neighbor_val)) {
                curr_node->neighbors.push_back(nodes_map[neighbor_val]);
            }
        }
    }
    // return nodes_map[1] as `1` is the start value
    return nodes_map[1];
}

Node* clone(Node* node, unordered_map<Node*, Node*>& oldToNew) {
    if (oldToNew.count(node)) {
        return oldToNew[node];
    }

    Node* copy = new Node(node->val);
    oldToNew[node] = copy;
    for (Node* neighbour: node->neighbors) {
        copy->neighbors.push_back(clone(neighbour, oldToNew));
    }
    return copy;
}

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> oldToNew;
    return clone(node, oldToNew);
}

int main(void) {
    vector<vector<int>> adjList = {{2, 4}, {1, 3}, {2, 4}, {1, 3}}; // shows neighors of each node (index)
    Node* start = createGraphFromAdjList(adjList);

    Node* copyStart = cloneGraph(start);
    cout << copyStart->val << "\n";

    return 0;
}

/*
V -> Vertices
E -> Edges

Time Complexity: O(V + E), dfs or bfs
Space Complexity: O(V + E) for creating new graph + O(V) for hash map + O(V) for recursion stack
*/