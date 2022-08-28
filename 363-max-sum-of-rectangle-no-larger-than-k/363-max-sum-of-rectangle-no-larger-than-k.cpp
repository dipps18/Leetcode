class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int maxSum = INT_MIN;
        for(int l = 0; l < matrix[0].size(); l++)
        {
            vector<int> colSum(matrix.size(), 0);
            for(int r = l; r < matrix[0].size(); r++)
            {
                for(int row = 0; row < matrix.size(); row++)
                {
                    colSum[row] += matrix[row][r];
                }
                set<int> cum;
                cum.insert(0);
                int curSum = 0;
                for(int i = 0; i < colSum.size(); i++)
                {
                    curSum += colSum[i];
                    auto it = cum.lower_bound(curSum - k);
                    if(it != cum.end())
                        maxSum = max(maxSum, curSum- *it);
                    cum.insert(curSum);
                }
            }
        }
        return maxSum;
    }
};