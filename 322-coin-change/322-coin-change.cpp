class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[++amount];
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for(int i = 1; i < amount; i++)
        {
            dp[i] = INT_MAX;
            for(int coin : coins)
            {
                if(i - coin < 0) break;
                if(dp[i - coin] == 0)
                {
                    dp[i] = 1;
                    break;
                }
                if(dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount - 1] == INT_MAX ? -1 : dp[amount - 1];
    }

};