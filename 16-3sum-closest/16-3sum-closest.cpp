class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int s, t, minDiff = INT_MAX, res;
        sort(nums.begin(), nums.end());
        for(int f = 0; f < nums.size() - 2; f++)
        {
            s = f + 1;
            t = nums.size() - 1;
            while(s < t)
            {
                int sum = nums[f] + nums[s] + nums[t];
                if(abs(target - sum) < minDiff)
                {
                    minDiff = abs(target - sum);
                    res = sum;
                }
                if(sum == target) return sum;
                if(sum > target)
                    t--;
                else
                    s++;
                    
            }
        }
        return res;
    }
};