class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                bool sunk = false;
                sinkIsland(grid, sunk, i, j);
                if(sunk){
                    count++;
                }
            }
        }
        return count;
    }
    void sinkIsland(vector<vector<char>>& grid, bool& sunk, int i, int j)
    {
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) return;
        if(grid[i][j] == '0') return;
        sunk = true;
        grid[i][j] = '0';
        sinkIsland(grid, sunk, i + 1, j);
        sinkIsland(grid, sunk, i - 1, j);
        sinkIsland(grid, sunk, i, j + 1);
        sinkIsland(grid, sunk, i, j - 1);
    }
};