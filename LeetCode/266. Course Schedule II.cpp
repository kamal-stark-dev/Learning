// 210. Course Schedule II

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

bool dfs(int i, vector<int>& order, unordered_map<int, bool>& visited, vector<vector<int>>& adj) {
    if (visited.find(i) != visited.end()) {
        return visited[i]; // false(cycle detected) or true(can visit course)
    }

    visited.insert({i, false});
    for (int nei: adj[i]) {
        if (!dfs(nei, order, visited, adj)) return false;
    }
    visited[i] = true;
    order.push_back(i);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto it: prerequisites) {
        adj[it[0]].push_back(it[1]);
    }

    vector<int> order;
    unordered_map<int, bool> visited;
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, order, visited, adj)) {
            return {}; // not possible to complete all courses
        }
    }
    return order;
}

// Kahn's Algorithm

vector<int> findOrder_Kahn(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (auto& it: prerequisites) {
        adj[it[0]].push_back(it[1]);
        inDegree[it[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int nei: adj[node]) {
            inDegree[nei]--;
            if (inDegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    if (order.size() == 0) return {};
    reverse(order.begin(), order.end());
    return order;
}

int main(void) {
    // int numCourses = 2;
    int numCourses = 6;
    // vector<vector<int>> prerequisites = {{0, 1}};
    vector<vector<int>> prerequisites = {{2, 0}, {1, 0}, {0, 3}, {3, 4}, {3, 5}};

    vector<int> order = findOrder_Kahn(numCourses, prerequisites);
    for (int course: order) {
        cout << course << " -> ";
    }
    cout << "DONE\n";

    return 0;
}

/*
Time Complexity: O(V + E), visiting all nodes and edges.
Space Complexity: O(V + E), storing adj, order and visited.
*/