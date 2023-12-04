#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> edge;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findSet(int v) {
        if (v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }

    void unionSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

int kruskalMST(vector<edge>& edges, int vertices) {
    sort(edges.begin(), edges.end());
    UnionFind uf(vertices);
    int minCost = 0;

    for (const auto& e : edges) {
        int u = e.second.first;
        int v = e.second.second;
        int w = e.first;

        if (uf.findSet(u) != uf.findSet(v)) {
            minCost += w;
            uf.unionSets(u, v);
        }
    }

    return minCost;
}

int main() {
    int vertices = 4;
    vector<edge> edges;

    // Example edges with weights
    edges.push_back({5, {0, 1}});
    edges.push_back({8, {0, 2}});
    edges.push_back({9, {1, 2}});
    edges.push_back({2, {1, 3}});
    edges.push_back({6, {2, 3}});

    int minCost = kruskalMST(edges, vertices);
    cout << "Minimum Spanning Tree Cost (Kruskal's): " << minCost << endl;

    return 0;
}
