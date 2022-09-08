class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto r : row)
            for(int i = 0; i < matrix[0].size();i++)
                matrix[r][i] = 0;
        
        for(auto c : col)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][c] = 0;
        }
};