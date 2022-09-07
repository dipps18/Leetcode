class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        int n = wordDict.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(s, wordDict, dp, 0);
    }
    
    bool helper(string& s, vector<string>& wordDict, vector<vector<int>>& dp, int idx)
    {
        if(idx == s.size()) return true;
        if(idx > s.size()) return false;
        for(int i = 0; i < wordDict.size(); i++)
        {
            if(dp[idx][i] == 0) continue;
            //If we haven't checked the sequence yet
            if(dp[idx][i] == -1)
            {
                if(wordDict[i].size() + idx <= s.size())
                {
                    int j = idx;
                    //For checking that the letters match
                    for(char ch : wordDict[i])
                    {
                        if(s[j++] != ch) 
                        {
                            dp[idx][i] = 0;
                            break;
                        }
                    }
                }
                else 
                    dp[idx][i] = 0;
                
                // The letters match
                if(dp[idx][i] != 0)
                {
                    if(helper(s, wordDict, dp, idx + wordDict[i].size()) == true)
                        return true;
                    else
                        dp[idx][i] = 0;
                }
            }
        }
        return false;
    }
};