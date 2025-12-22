// 210. Course Schedule II

#include <iostream>
#include <unordered_map>
#include <vector>
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

int main(void) {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{0, 1}};

    vector<int> order = findOrder(numCourses, prerequisites);
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