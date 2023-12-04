#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int shortestDist(vector<vector<int>> &graph, int stages) {
   vector<int> cost(stages+1,INF);
   // last stage se pahle
   cost[stages-1]=0;
   for(int i=stages-2;i>=0;i--){
    for(int j=i;j<stages;j++){
        if(graph[i][j] == INF) 
            continue;
        cost[i] = min(cost[i],graph[i][j] + cost[j]);
    }
   }
   return cost[0];
}

int main() {
    int stages = 8; // Adjust the number of stages accordingly

    vector<vector<int>> graph = {
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF}};


    cout << shortestDist(graph, stages) << endl;

    return 0;
}
