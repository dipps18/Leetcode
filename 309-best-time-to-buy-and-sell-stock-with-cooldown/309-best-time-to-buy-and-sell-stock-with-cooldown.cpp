class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 ,-1));
        return dfs(prices, 0, 1, dp);
    }
    
    int dfs(vector<int>& prices, int day, int buying, vector<vector<int>>&dp)
    {
        if(day >= (int)prices.size()) return 0;
        if(dp[day][buying] != -1) return dp[day][buying];
        if(buying)
        {
            int buying_later = dfs(prices, day + 1, 1, dp);
            int buying_now = dfs(prices, day + 1, 0, dp) - prices[day];
            dp[day][1] = max(buying_now, buying_later);
            return dp[day][1];
        }
        else
        {
            int selling_later = dfs(prices, day + 1, 0, dp);
            int selling_now = dfs(prices, day + 2, 1, dp) + prices[day];
            dp[day][0] = max(selling_now, selling_later);
            return dp[day][0];
        }
    }
};