class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL = 0, maxR = height[n - 1], l = 0, r = n - 1, cur = 0;
        int output = 0;
        while(l < r)
        {
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);
            int curWater = min(maxL, maxR) - height[cur];
            if(curWater > 0)
                output += curWater;
            cur = (maxL > maxR) ? --r : ++l;
        }
        return output;
    }
};