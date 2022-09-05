class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int j = 0, i = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> output;
        int left = 0, right = n - 1, bottom = m - 1, top = 0;
        while(output.size() < m*n)
        {
            for(int i = left; i <= right && output.size() < m*n; i++)
                output.push_back(matrix[top][i]);
            for(int i = top + 1; i <= bottom && output.size() < m*n; i++)
                output.push_back(matrix[i][right]);
            for(int i = right - 1; i >= left && output.size() < m*n; i--)
                output.push_back(matrix[bottom][i]);
            for(int i = bottom - 1; i > top && output.size() < m*n; i--)
                output.push_back(matrix[i][left]);
            left++; right--; top++; bottom--;
        }
        return output;
    }
};