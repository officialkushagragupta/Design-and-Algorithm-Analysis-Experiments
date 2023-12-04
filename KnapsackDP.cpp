#include <bits/stdc++.h>
using namespace std;

int wt[3] = {15, 30, 45};
int val[3] = {60, 100, 150};
int dp[5][51]; // Increase the size to handle indices from 0 to 4 and weights from 0 to 50

int knapsackDP(int n, int w)
{
    if (n == 0 || w <= 0)
    {
        return 0;
    }

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    if (wt[n - 1] > w)
    {
        dp[n][w] = knapsackDP(n - 1, w);
    }
    else
    {
        dp[n][w] = max(knapsackDP(n - 1, w), val[n - 1] + knapsackDP(n - 1, w - wt[n - 1]));
    }

    return dp[n][w];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n = 3;
    int w = 50;

    cout << knapsackDP(n, w) << endl;
    return 0;
}
