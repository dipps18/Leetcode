class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int x = INT_MAX, min_x = INT_MAX, y = INT_MAX, z = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < x && y == INT_MAX && z==INT_MAX)
            {
                x = nums[i];
                min_x = min(nums[i], min_x);
                y = INT_MAX;
                z = INT_MAX;
            }
            else if(nums[i] > x || nums[i] > min_x)
            {
                if(nums[i] < y)
                {
                    y = nums[i];
                    z = INT_MAX;
                }
                else if(nums[i] > y)
                {
                    z = nums[i];
                    return true;
                }
            }
            else if(nums[i] < min_x) min_x = nums[i];
        }
        return false;
    }
};