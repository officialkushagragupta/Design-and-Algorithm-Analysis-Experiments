#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int primMST(vector<vector<pii>>& adj, int vertices) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(vertices, false);
    int minCost = 0;

    pq.push({0, 0}); // {cost, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (visited[u]) continue;

        minCost += cost;
        visited[u] = true;

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    return minCost;
}

int main() {
    int vertices = 4;
    vector<vector<pii>> adj(vertices);

    // Example edges with weights
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    adj[0].push_back({2, 8});
    adj[2].push_back({0, 8});
    adj[1].push_back({2, 9});
    adj[2].push_back({1, 9});
    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});
    adj[2].push_back({3, 6});
    adj[3].push_back({2, 6});

    int minCost = primMST(adj, vertices);
    cout << "Minimum Spanning Tree Cost (Prim's): " << minCost << endl;

    return 0;
}
