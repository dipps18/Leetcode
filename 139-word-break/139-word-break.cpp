class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        vector<int> dp(m, -1);
        return helper(s, wordDict, dp, 0);
    }
    
    bool helper(string& s, vector<string>& wordDict, vector<int>& dp, int idx)
    {
        if(idx == s.size()) return true;
        if(idx > s.size()) return false;
        if(dp[idx] != -1) return dp[idx];
        for(int i = 0; i < wordDict.size(); i++)
        {
            bool found = true;
            if(wordDict[i].size() + idx <= s.size())
            {
                int j = idx;
                //For checking that the letters match
                for(char ch : wordDict[i])
                {
                    if(s[j++] != ch) 
                    {
                        found = false;
                        break;
                    }
                }
                // The letters match
                if(found)
                {
                    if(helper(s, wordDict, dp, idx + wordDict[i].size()) == true)
                        return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = false;
    }
};