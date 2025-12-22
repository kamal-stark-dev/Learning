// 547. Number of Provinces

#include <iostream>
#include <vector>
using namespace std;

int find(int node, vector<int>& parent) {
    int p = node;
    while (p != parent[p]) {
        // inverse Ackermann
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

int union_nodes(int n1, int n2, vector<int>& parent, vector<int>& rank) {
    int p1 = find(n1, parent), p2 = find(n2, parent);

    if (p1 == p2) return 0;

    if (rank[p1] > rank[p2]) {
        parent[p2] = p1;
        rank[p1] += rank[p2];
    }
    else {
        parent[p1] = p2;
        rank[p2] += rank[p1];
    }
    return 1;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    vector<int> parent(n), rank(n, 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int res = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && isConnected[i][j]) {
                res -= union_nodes(i, j, parent, rank);
            }
        }
    }
    return res;
}

int main(void) {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << findCircleNum(isConnected) << " province(s)\n";

    return 0;
}

/*
alpha(n) -> nearly a constant function O(1)

Time Complexity: O((V + E) * alpha(V))
Space Complexity: O(V), for parent and rank storage
*/