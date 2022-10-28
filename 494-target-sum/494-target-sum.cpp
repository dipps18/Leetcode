class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(2001, vector<int>(21, -1));
        return dfs(nums, target, 0, 0, dp);
    }
    
    int dfs(vector<int>& nums, int& target, int curSum, int curIndex, vector<vector<int>>&dp)
    {
        if(curIndex == nums.size() || dp[curSum + 1000][curIndex] != -1)
        {
            if(dp[curSum + 1000][curIndex] != -1)
                return dp[curSum + 1000][curIndex];
            else if(curSum == target)
                return 1;
            return 0;
        }
        int diff = dfs(nums, target, curSum - nums[curIndex], curIndex + 1, dp);
        int sum = dfs(nums, target, curSum + nums[curIndex], curIndex + 1, dp);
        dp[curSum + 1000][curIndex] = sum + diff;
        return dp[curSum + 1000][curIndex];
    }
};