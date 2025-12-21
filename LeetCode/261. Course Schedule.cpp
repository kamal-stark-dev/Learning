// 207. Course Schedule

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool dfs(int course, unordered_set<int>& visited, vector<vector<int>>& adjList) {
    // base cases
    if (visited.find(course) != visited.end()) return false; // loop detected
    if (adjList[course].empty()) return true;

    visited.insert(course);
    for (int requisite: adjList[course]) {
        if (!dfs(requisite, visited, adjList)) return false;
    }
    visited.erase(course);
    adjList[course] = {}; // optimization - once a node is confirmed acyclic, we erase its edges, preventing re-work in future DFS calls.
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses, vector<int>());

    for (auto it: prerequisites) {
        int course = it[0], requsite = it[1];
        adjList[course].push_back(requsite);
    }

    unordered_set<int> visited;
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, visited, adjList)) return false;
    }
    return true;
}

int main(void) {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}}; // true
    // vector<vector<int>> prerequisites = {{1, 0}, {0, 1}}; // false

    cout << (canFinish(numCourses, prerequisites) ? "true": "false") << "\n";

    return 0;
}

/*
V -> no. of vertices(nodes)
E -> no. of edges

Time Complexity: O(V + E)
Space Complexity: O(V) for `visited` & O(V + E) for `adjList`
*/