class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<int>> output;
        bool pacific = false, atlantic = false;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                atlantic = false;
                pacific = false;
                if(helper(heights, i, j, dp, atlantic, pacific))
                {
                    output.push_back({i, j});
                    dp[i][j] = 1;
                }
                else dp[i][j] = 0;
        
            }
        }
        return output;
    }
    
    bool helper(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& dp, bool& atlantic, bool& pacific)
    {
        if(i == 0 || j == 0)
        {
            pacific = true;
        }
        if(i == heights.size() - 1 && j == 0 || (j == heights[0].size() - 1 && i == 0))
        {
            atlantic = true;
            pacific = true;
            return true;
        }
        if(i == heights.size() - 1 || j == heights[0].size() - 1)
        {
            atlantic = true;
        }
        if(atlantic && pacific) return true;
        if(heights[i][j] == -1) return false;
        if(dp[i][j] == 1) 
        {
            atlantic = true;
            pacific = true;
            return dp[i][j]; 
        }
        if(atlantic && pacific) return true;
        int temp = heights[i][j];
        heights[i][j] = -1;
        if(i + 1 < heights.size() && temp >= heights[i + 1][j])
            helper(heights, i + 1, j, dp, atlantic, pacific);
        if(i - 1 >= 0 && temp >= heights[i - 1][j])
            helper(heights, i - 1, j, dp, atlantic, pacific);
        if(j + 1 < heights[0].size() && temp >= heights[i][j + 1])
            helper(heights, i, j + 1, dp, atlantic, pacific);
        if(j - 1 >= 0 && temp >= heights[i][j - 1])
            helper(heights, i, j - 1, dp, atlantic, pacific);
        heights[i][j] = temp;
        return (atlantic && pacific);
    }
};