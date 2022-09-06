class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJump = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] + i >= minJump)
                minJump = i;
        }
        return minJump == 0;
    }
};