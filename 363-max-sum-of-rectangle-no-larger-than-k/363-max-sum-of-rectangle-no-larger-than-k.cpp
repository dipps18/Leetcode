class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int maxSum = INT_MIN;
        bool rowGreater = matrix[0].size() <= matrix.size();
        int m = min(matrix.size(), matrix[0].size());
        int n = max(matrix.size(), matrix[0].size());
        for(int l = 0; l < m; l++)
        {
            vector<int> colSum(n, 0);
            for(int r = l; r < m; r++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(rowGreater) colSum[k] += matrix[k][r];
                    else colSum[k] += matrix[r][k];
                }
                set<int> cum;
                cum.insert(0);
                int curSum = 0;
                for(int i = 0; i < colSum.size(); i++)
                {
                    curSum += colSum[i];
                    auto it = cum.lower_bound(curSum - k);
                    if(it != cum.end())
                    {
                        maxSum = max(maxSum, curSum- *it);
                        if(maxSum == k) return k;
                    }
                    cum.insert(curSum);
                }
            }
        }
        return maxSum;
    }
};