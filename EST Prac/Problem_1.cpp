class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        
        if(n == 1) return 0;
        
        int N = 1 << n;
        vector<vector<int>> dp(N, vector<int>(n, 1e9));
        
        dp[1][0] = 0;
        
        for(int mask = 1; mask < N; mask++){
            for(int u = 0; u < n; u++){
                if(mask & (1 << u)){
                    for(int v = 0; v < n; v++){
                        if(!(mask & (1 << v))){
                            dp[mask | (1 << v)][v] = min(
                                dp[mask | (1 << v)][v],
                                dp[mask][u] + cost[u][v]
                            );
                        }
                    }
                }
            }
        }
        
        int ans = 1e9;
        for(int u = 1; u < n; u++){
            ans = min(ans, dp[N-1][u] + cost[u][0]);
        }
        
        return ans;
    }
};