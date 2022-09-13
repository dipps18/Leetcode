class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rowTop = 0, rowBottom = m - 1, colLeft = 0, colRight = n - 1;
        bool rowFound = false;
        int row;
        while(rowTop <= rowBottom)
        {
            row = (rowTop + rowBottom)/2;
            if(matrix[row][0] > target)
            {
                rowBottom = row - 1;
                continue;
            }
            else if(matrix[row][n - 1] >= target)
            {
                rowFound = true;
                break;
            }
            rowTop = row + 1;
        }
        if(!rowFound) return false;
        
        while(colLeft <= colRight)
        {
            if(matrix[row][colRight] < target)
                break;
            int col = (colLeft + colRight)/2;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                colRight = col - 1;
            else
                colLeft = col + 1;
        }
        return false;
    }
};