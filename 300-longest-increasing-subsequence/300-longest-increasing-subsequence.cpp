class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> output;
        output.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            auto it = lower_bound(output.begin(), output.end(), nums[i]);
            if(it == output.end())
                output.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return output.size();
    }
};