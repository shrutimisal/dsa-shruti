#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) with Path Compression + Union by Rank
class DSU {
    vector<int> parent;   // stores parent of each node
    vector<int> rank;     // stores rank (approx height of tree)

public:
    // Constructor: initialize DSU
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);

        // Initially, every node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // Find the ultimate parent (with path compression)
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        // Path compression: directly connect node to root
        return parent[node] = findParent(parent[node]);
    }

    // Union of two sets using rank
    void unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        // If already in same set → do nothing
        if (parentU == parentV) return;

        // Attach smaller tree under bigger tree
        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        }
        else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        }
        else {
            // Same rank → choose one and increase rank
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
};

// Comparator to sort edges based on weight
bool compareEdges(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];  // sort by weight
}

// Kruskal's Algorithm to find MST cost
int kruskalsMST(int vertices, vector<vector<int>> &edges) {

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(vertices);

    int totalCost = 0;   // MST cost
    int edgesUsed = 0;   // number of edges included in MST

    // Step 2: Process edges
    for (auto &edge : edges) {
        int u = edge[0];   // source
        int v = edge[1];   // destination
        int weight = edge[2];

        // Step 3: Check if adding edge forms a cycle
        if (dsu.findParent(u) != dsu.findParent(v)) {

            // No cycle → include edge
            dsu.unionByRank(u, v);
            totalCost += weight;
            edgesUsed++;

            // MST complete when we have V-1 edges
            if (edgesUsed == vertices - 1)
                break;
        }
    }

    return totalCost;
}

int main() {

    // Each edge: {source, destination, weight}
    vector<vector<int>> edges = {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}
    };

    cout << kruskalsMST(4, edges);

    return 0;
}