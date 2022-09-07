class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        vector<bool> dp(m + 1, false);
        dp[m] = true;
        for(int i = m - 1; i >= 0; i--)
        {
            string sub;
            for(int j = i; j < s.size(); j++)
            {
                sub += s[j];
                for(string word : wordDict)
                {
                    if(word == sub && dp[i + sub.size()]) 
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};