class Solution {
public:

    void push_if_valid(priority_queue<int>& queue, unordered_set<int>& addedDepths,
       vector<vector<int>>& grid, int i, int j, int rows, int cols) 
    {
        int pos = i * rows + j;
        if(i < rows && j < cols && i >= 0 && j >= 0 && 
        addedDepths.find(grid[i][j]) == addedDepths.end())
        {
            queue.push(-grid[i][j]);
            addedDepths.insert(grid[i][j]);
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        std::priority_queue<int> queue;
        std::unordered_set<int> addedDepths;
        std::unordered_map<int, int> depthIdx;
        int res = INT_MIN;
        int rows = grid.size(), cols = grid[0].size();
        queue.push(-grid[0][0]);
        addedDepths.insert(grid[0][0]);

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                int pos = i * rows + j;
                depthIdx[grid[i][j]] = pos;
            }
        }

        while(!queue.empty())
        {
            int cur_depth = -queue.top();
            int cur_pos = depthIdx[cur_depth];
            queue.pop();
            int i = cur_pos / cols;
            int j = cur_pos % cols;
            res = max(res, cur_depth);
            if(i == rows - 1 && j == cols - 1)
            {
                return res;
            }

            push_if_valid(queue, addedDepths, grid, i, j - 1, rows, cols);
            push_if_valid(queue, addedDepths, grid, i, j + 1, rows, cols);
            push_if_valid(queue, addedDepths, grid, i - 1, j, rows, cols);
            push_if_valid(queue, addedDepths, grid, i + 1, j, rows, cols);
        }

        return res;
    }
};