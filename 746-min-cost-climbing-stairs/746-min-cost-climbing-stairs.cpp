class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(1001, -1);
        return min(dfs(cost, 0, dp), dfs(cost, 1, dp));
    }
    
    int dfs(vector<int>& cost, int step, vector<int>& dp)
    {
        if(step >= cost.size()) return 0;
        if(dp[step] != -1) return dp[step];
        dp[step] = min(dfs(cost, step + 1, dp), dfs(cost, step + 2,dp)) + cost[step];
        return dp[step];
    }
};