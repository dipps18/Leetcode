class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(robHelper(nums, 0, nums.size() - 1), robHelper(nums, 1, nums.size()));
    }
    
    int robHelper(vector<int>& nums, int start, int end)
    {
        vector<int> maxLoot(nums.size(), 0);
        maxLoot[start] = nums[start];
        maxLoot[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i < end; i++)
        {
            maxLoot[i] = max(maxLoot[i - 1], maxLoot[i - 2] + nums[i]);
        }
        return maxLoot[end - 1];
    }
};