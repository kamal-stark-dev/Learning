// M - Coloring Problem

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int color, vector<int> adj[], vector<int>& colors) {
    for (int neighbour: adj[node]) {
        if (colors[neighbour] == color) return false;
    }
    return true;
}

bool solve(int node, int n, int m, vector<int> adj[], vector<int>& colors) {
    if (node == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, adj, colors)) {
            colors[node] = c;
            if(solve(node + 1, n, m, adj, colors)) return true;
            colors[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(int n, int m, vector<vector<int>>& edges) {
    vector<int> adj[n];

    for (auto& edge: edges) {
        int a = edge[0], b = edge[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> colors(n, 0);
    return solve(0, n, m, adj, colors);
}

int main(void) {
    int n = 4, m = 3;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}
    };

    cout << "This graph can" << (graphColoring(n, m, edges) ? "" : "not ") << " be colored with " << m << " colors such that no two adjacent edges have the same color.\n";

    return 0;
}

/*
Time Complexity: O(m ^ n), for each vertex we try m colors in worst case [pruning `isSafe` makes it faster in practice]
Space Complexity: O(n + e), e -> edges, adjacency list storage (O(n + e)) + recursion stack (O(n)) + colors array (O(n)).
*/