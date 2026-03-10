#include<bits/stdc++.h>
using namespace std;

int dpFun(vector<int>& arr, int target, int idx, vector<vector<int>> &dp, int curr){
    if(idx >= arr.size()){
        return target == curr;
    }
    if(curr > target){
        return 0;
    }
    if(dp[idx][curr] != -1){
        return dp[idx][curr];
    }
    int pick = dpFun(arr, target, idx+1, dp, curr+arr[idx]);
    int npick = dpFun(arr, target, idx+1, dp, curr);
    return dp[idx][curr] = pick+npick;

}

int perfectSum(vector<int>& arr, int target) {
    // code here
    vector<vector<int>> dp(arr.size()+1, vector<int>(target+1, -1));
    return dpFun(arr, target, 0, dp, 0);
}
