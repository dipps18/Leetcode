class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(robHelper(nums, 0, nums.size() - 1), robHelper(nums, 1, nums.size()));
    }
    
    int robHelper(vector<int>& nums, int start, int end)
    {
        int max_two_before = nums[start];
        int max_one_before = max(nums[start], nums[start + 1]);
        int max_cur = max_one_before;
        for(int i = start + 2; i < end; i++)
        {
            max_cur = max(max_one_before, nums[i] + max_two_before);
            max_two_before = max_one_before;
            max_one_before = max_cur;
        }
        return max_cur;
    }
};