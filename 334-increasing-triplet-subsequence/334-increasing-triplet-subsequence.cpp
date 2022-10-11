class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int x = INT_MAX, min_x = INT_MAX, y = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < x && y == INT_MAX)
            {
                x = nums[i];
                min_x = min(nums[i], min_x);
            }
            else if(nums[i] > x || nums[i] > min_x)
            {
                if(nums[i] < y)
                    y = nums[i];
                else if(nums[i] > y)
                    return true;
            }
            else if(nums[i] < min_x)
                min_x = nums[i];
        }
        return false;
    }
};