class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return dfs(amount, 0, coins, dp);
    }
    
    int dfs(int amountLeft, int index, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(amountLeft == 0)
            return dp[index][amountLeft] = 1;
        if(amountLeft < 0 || index == coins.size()) 
            return 0;
        if(dp[index][amountLeft] != -1) 
            return dp[index][amountLeft];
        
        dp[index][amountLeft] = dfs(amountLeft - coins[index], index, coins, dp) +                                           dfs(amountLeft, index + 1, coins, dp);
        return dp[index][amountLeft];
    }
};