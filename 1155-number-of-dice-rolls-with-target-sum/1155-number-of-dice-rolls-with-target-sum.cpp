class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        return dfs(n,k,target,dp);
    }
    
    int dfs(int n, int k, int target, vector<vector<int>>& dp)
    {
        if(target == 0 && n > 0) return 0;
        if((target > 0 && n == 0) || target < 0 || target > n * k) return 0;
        if(target == 0 && n == 0) return 1;
        if(dp[n][target]) return dp[n][target];
        for(int i = min(target, k); i > 0; i--)
        {
            dp[n][target] = (dp[n][target] + dfs(n - 1, k, target - i, dp)) % 1000000007;
        }
        return dp[n][target];    
    }
};