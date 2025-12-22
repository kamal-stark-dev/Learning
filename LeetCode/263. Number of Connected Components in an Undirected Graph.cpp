// Number of Connected Components in an Undirected Graph - https://neetcode.io/problems/count-connected-components/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[i] = true;

    for (int nei: adj[i]) {
        if (!visited[nei]) {
            dfs(nei, visited, adj);
        }
    }
}

int countComponents_Traversal(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]); // we need to make it directed to count components correctly
    }

    int components = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj);
            components++;
        }
    }
    return components;
}

// below is the union find approach

int find(int node, vector<int>& parent) {
    int p_node = node;

    while (p_node != parent[p_node]) {
        parent[p_node] = parent[parent[p_node]]; // this line is gold -> it amortizes the path (making it O(a(n)) which is nearly as good as O(1))
        p_node = parent[p_node];
    }
    return p_node;
}

int union_nodes(int n1, int n2, vector<int>& parent, vector<int>& rank) {
    int p1 = find(n1, parent), p2 = find(n2, parent);

    if (p1 == p2) return 0; // same parent already connected

    if (rank[p2] > rank[p1]) {
        parent[p1] = p2;
        rank[p2] += rank[p1];
    }
    else {
        parent[p2] = p1;
        rank[p1] += rank[p2];
    }
    return 1;
}

int countComponents_UnionFind(int n, vector<vector<int>>& edges) {
    vector<int> parent(n), rank(n, 1);
    for (int i = 0; i < n; i++) parent[i] = i;

    int res = n;
    for (auto& it: edges) {
        res -= union_nodes(it[0], it[1], parent, rank);
    }
    return res;
}

int main(void) {
    // int n = 3;
    // vector<vector<int>> edges = {{0, 1}, {0, 2}}; // 1

    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}}; // 2

    cout << countComponents_UnionFind(n, edges) << " connected component(s)\b";

    return 0;
}

/*
alpha(n) -> inverse Ackermann is painfully slow-growing (nearly O(1))

Time Complexity: O((v + E) * alpha(V))
Space Complexity: O(V)
*/

/*
Why alpha(n) is basically 1:
n                                   alpha(n)
10^6                                <= 4
10^18                               <= 5
Number of atoms in universe         <= 5
*/