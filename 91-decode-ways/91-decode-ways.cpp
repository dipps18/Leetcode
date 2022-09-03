class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(100, 0);
        return helper(s, 0, dp);
    }
    
    int helper(string& s, int i, vector<int>&dp)
    {        
        if(s[i] == '0') return dp[i] = 0;
        if(i >= s.size()) return 1;
        if(dp[i]) return dp[i];
    
        int res = helper(s, i + 1, dp);
        if(i + 1 < s.size() && ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1'))
            res += helper(s, i + 2, dp);
        dp[i] = res;
        return res;
    }
};