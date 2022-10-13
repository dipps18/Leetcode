class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(100001, -1);
        dp[nums.size() - 1] = 0;
        return(dfs(nums, 0, dp));
    }
    
    int dfs(vector<int>& nums, int step, vector<int>& dp)
    {
        if(step >= nums.size()) return 0;
        if(dp[step] != -1) return dp[step];
        dp[step] = INT_MAX - 1;
        for(int i = 1; i <= nums[step]; i++)
        {
            dp[step] = min(dp[step], dfs(nums, step + i, dp) + 1);
            if(dp[step] == 1) return dp[step];
        }
        return dp[step];        
    }
};