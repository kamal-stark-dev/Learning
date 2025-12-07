// Graphs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbour: graph[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbour: graph[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main(void) {
    int n = 8, m = 10;
    graph.assign(n + 1, {});
    visited.assign(n + 1, false);

    vector<pair<int, int>> connections = {{0, 1}, {0, 3}, {1, 2}, {3, 6}, {3, 4}, {3, 7}, {4, 2}, {4, 5}, {5, 2}, {5, 4}};

    for (auto [u, v]: connections) {
        graph[u].push_back(v);
        graph[v].push_back(u); // remove this to make it directed graph
    }

    int start = 0; // or any other starting node
    cout << "DFS: ";
    dfs(start);
    cout << "\n";


    visited.assign(n + 1, false);
    // to find the number of clusters in the graph
    int components = 0;
    for (int node = 0; node < n; node++) {
        if (!visited[node]) {
            components++;
            dfs(node); // explore current cluster fully
        }
    }
    cout << "Number of connected components: " << components << "\n";

    visited.assign(n + 1, false);
    start = 0;
    cout << "BFS: ";
    bfs(start);
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/