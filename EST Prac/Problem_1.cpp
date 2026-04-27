#include<bits/stdc++.h>
using namespace std;

int tsp(int n, vector<vector<int>>& cost) {
    int N = 1<<n;
    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));
    
    dp[1][0] = 0; // start from node 0
    
    for(int mask = 1; mask < N; mask++) {
        for(int u = 0; u < n; u++) {
            if(mask & (1<<u)) {
                for(int v = 0; v < n; v++) {
                    if(!(mask & (1<<v))) {
                        dp[mask | (1<<v)][v] = min(
                            dp[mask | (1<<v)][v],
                            dp[mask][u] + cost[u][v]
                        );
                    }
                }
            }
        }
    }
    
    int ans = INT_MAX;
    for(int u = 1; u < n; u++) {
        ans = min(ans, dp[N-1][u] + cost[u][0]);
    }
    
    return ans;
}