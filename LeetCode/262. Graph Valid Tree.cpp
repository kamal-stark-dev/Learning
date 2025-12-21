// Graph Valid Tree - https://neetcode.io/problems/valid-tree/
// 261. Graph Valid Tree - LeetCode Premium

#include <iostream>
#include <vector>
// #include <unordered_set>
using namespace std;

void dfs(int node, vector<bool>& visited, const vector<vector<int>>& adjList) {
    visited[node] = true;

    for (int nei: adjList[node]) {
        if (!visited[nei]) {
            dfs(nei, visited, adjList);
        }
    }
}

bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<vector<int>> adjList(n);
    for (auto& it: edges) {
        int node1 = it[0], node2 = it[1];
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    // unordered_set<int> visited;
    vector<bool> visited(n, false);

    int startNode = 0;
    dfs(startNode, visited, adjList);

    for (bool v: visited) {
        if (!v) return false;
    }
    return true;
}

int main(void) {
    int n = 5;
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}}; // true
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}; // false

    cout << (validTree(n, edges) ? "true": "false") << "\n";

    return 0;
}

/*
Time Complexity: O(V + E), for visiting all nodes
Space Complexity: O(V + E), adjList
*/