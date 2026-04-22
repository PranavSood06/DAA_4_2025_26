class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int x : arr) total += x;
        
        vector<vector<bool>> dp(n+1, vector<bool>(total+1, false));
        dp[0][0] = true;
        
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= total; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= arr[i-1] && dp[i-1][j-arr[i-1]])
                    dp[i][j] = true;
            }
        
        int ans = INT_MAX;
        for(int s = 0; s <= total/2; s++)
            if(dp[n][s])
                ans = min(ans, total - 2*s);
        
        return ans;
    }
};