class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>> dp(t1.size(), vector<int>(t2.size(), -1));
        return helper(t1, t2, dp, 0, 0);
    }
    
    int helper(string& t1, string& t2, vector<vector<int>>& dp, int i, int j)
    {
        if(i >= t1.size() || j >= t2.size() || i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(t1[i] == t2[j])
            dp[i][j] = 1 + helper(t1, t2, dp, i + 1, j + 1);
        else
            dp[i][j] = max(helper(t1, t2, dp, i + 1, j), helper(t1, t2, dp, i, j + 1));
        return dp[i][j];
    }
};


