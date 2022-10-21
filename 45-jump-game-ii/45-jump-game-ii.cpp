class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd = 0, curFarthest = 0, jumps = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            curFarthest = max(curFarthest, i + nums[i]);
            if(i == curEnd)
            {
                jumps++;
                curEnd = curFarthest;
            }
            if(curEnd == nums.size() - 1) break;
        }
        return jumps;
    }
};