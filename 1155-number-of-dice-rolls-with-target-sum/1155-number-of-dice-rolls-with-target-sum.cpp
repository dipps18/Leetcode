class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return dfs(n,k,target,dp);
    }
    
    int dfs(int n, int k, int target, vector<vector<int>>& dp)
    {
        if(dp[n][target] != -1) return dp[n][target];
        if(target == 0 && n > 0) return dp[n][target] = 0;
        if((target > 0 && n == 0) || target > n * k) return dp[n][target] = 0;
        if(target == 0 && n == 0) return dp[n][target] = 1;
        dp[n][target] = 0;
        for(int i = min(target, k); i > 0; i--)
        {
            dp[n][target] = (dp[n][target] + dfs(n - 1, k, target - i, dp)) % 1000000007;
        }
        return dp[n][target];    
    }
};