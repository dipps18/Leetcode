class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        unordered_map<int, int> dp;
        int maxFreq = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            dfs(nums, dp, maxFreq, nums[i], i);
        }
        return maxFreq;
    }
    
    int dfs(vector<int>& nums, unordered_map<int, int>& dp, int& maxFreq, int val, int idx)
    {
        if(dp.find(idx) != dp.end()) return dp[idx];
        dp[idx] = 1;
        for(int i = idx + 1; i < nums.size(); i++)
        {
            if(nums[i] > val)
                dp[idx] = max(dfs(nums, dp, maxFreq, nums[i], i) + 1, dp[idx]);
        }
        maxFreq = max(maxFreq, dp[idx]);
        return dp[idx];
    }
};