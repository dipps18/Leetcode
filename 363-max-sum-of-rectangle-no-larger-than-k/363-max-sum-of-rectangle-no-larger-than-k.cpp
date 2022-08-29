class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int maxSum = INT_MIN;
        bool rowGreater = matrix[0].size() <= matrix.size();
        int m = min(matrix.size(), matrix[0].size());
        int n = max(matrix.size(), matrix[0].size());
        for(int l = 0; l < m; l++)
        {
            vector<int> sum(n, 0);
            for(int r = l; r < m; r++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(rowGreater) sum[k] += matrix[k][r];
                    else sum[k] += matrix[r][k];
                }
                int curSum = 0;
                int kMaxSum = 0;
                for(int i = 0; i < n; i++)
                {
                    curSum = max(sum[i], curSum + sum[i]);
                    kMaxSum = max(curSum, kMaxSum);
                }
                if(kMaxSum <= k && kMaxSum > 0){
                    maxSum = max(kMaxSum, maxSum);
                    continue;
                }
                curSum = 0;
                set<int> cum;
                cum.insert(0);
                for(int i = 0; i < sum.size(); i++)
                {
                    curSum += sum[i];
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