class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<int>> output;
        
        //vertical
        for(int i = 0; i < m; i++)
        {
            dfs(heights, pacific, -1, i, 0);
            dfs(heights, atlantic, -1, i, n - 1);
        }
        
        //horizontal
        for(int j = 0; j < n; j++)
        {
            dfs(heights, pacific, -1, 0, j);
            dfs(heights, atlantic, -1, m - 1, j);
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(atlantic[i][j] && pacific[i][j])
                    output.push_back({i, j});
            }
        }
        return output;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int prev, int i, int j)
    {
        if(i < 0 || j < 0 || j >= heights[0].size() || i >= heights.size() ||
           heights[i][j] == -1 || visited[i][j] || prev > heights[i][j]) return;
        visited[i][j] = true;
        int temp = heights[i][j];
        heights[i][j] = -1;
        dfs(heights, visited, temp, i + 1, j); dfs(heights, visited, temp, i - 1, j); 
        dfs(heights, visited, temp, i, j + 1); dfs(heights, visited, temp, i, j - 1);
        heights[i][j] = temp;
    }
};