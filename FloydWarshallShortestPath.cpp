#include<bits/stdc++.h>
using namespace std;

int floydWarshall(int n, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    // Initializing the distance matrix with edge weights
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        dist[u][v] = wt;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9 && (dist[i][k] + dist[k][j] < dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist[src][dest];
}

int main() {
    int n = 5; // Number of vertices
    int m = 8; // Number of edges
    int src = 0;
    int dest = 4;

    // Edge list (u, v, wt)
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 8},
        {1, 2, 9},
        {1, 3, 2},
        {2, 3, 6},
        {3, 1, -7},  
        {2, 4, 4},
        {3, 4, 3}
    };

    int shortestPath = floydWarshall(n, edges, src, dest);

    if (shortestPath == 1e9) {
        cout << "No path from " << src << " to " << dest << "." << endl;
    } else {
        cout << "Shortest Path from " << src << " to " << dest << ": " << shortestPath << endl;
    }

    return 0;
}
