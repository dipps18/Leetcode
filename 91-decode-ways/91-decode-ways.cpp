class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(101, -1);
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }
    
    int dfs(string s, int i, vector<int>& dp)
    {
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return dp[i] = 0;
        int res = dfs(s, i + 1, dp);
        if(i + 1 < s.size() && ((s[i] == '2' && s[i + 1] <= '6' && s[i + 1] >= '0') || s[i] == '1'))
            res += dfs(s, i + 2, dp);
        return dp[i] = res;
    }
};