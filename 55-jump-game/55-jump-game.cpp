class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> canReach(nums.size(), -1);
        return canJumpHelper(nums, 0, canReach);
    }
    
    bool canJumpHelper(vector<int>& nums, int cur, vector<int>& canReach)
    {
        if(cur == nums.size() - 1) return true;
        if(cur >= nums.size()) return false;
        if(canReach[cur] != -1) return canReach[cur];
        canReach[cur] = 0;
        for(int i = 1; i <= nums[cur]; i++)
        {
            if(canJumpHelper(nums, cur + i, canReach)) 
            {
                canReach[cur] = 1;
                return true;
            }
        }
        return false;
    }
};