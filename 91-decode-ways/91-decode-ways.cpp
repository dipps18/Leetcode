class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(100, 0);
        return helper(s, 0, dp);
    }
    
    int helper(string& s, int i, vector<int>&dp)
    {        
        if(i > s.size()) return 0;
        //Indicates that we have passed the last element or are on the last element
        //Eg: 12 -> When i = 1 and when i = 2
        if(i == s.size() || (i == s.size() - 1 && s[i] != '0')) return 1;
        if(s[i] == '0') return 0;    
        if(dp[i]) return dp[i];
        if(s[i] >= '2')
        {
            if((i + 1 < s.size() && s[i + 1] > '6') || s[i] > '2'){
                dp[i] = helper(s, i + 1, dp);
                return dp[i];
            }
        }
        dp[i] = helper(s, i + 2, dp) + helper(s, i + 1, dp);
        return dp[i];
    }
};