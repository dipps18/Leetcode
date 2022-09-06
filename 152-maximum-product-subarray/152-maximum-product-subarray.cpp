class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPrefix = nums[0], minPrefix = nums[0], res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < 0)
                swap(maxPrefix, minPrefix);
            maxPrefix = max(nums[i], nums[i] * maxPrefix);
            minPrefix = min(nums[i], nums[i] * minPrefix);
            res = max(res, maxPrefix);
        }
        return res;
    }
};