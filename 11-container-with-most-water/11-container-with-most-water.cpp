class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), left = 0, right = n - 1;
        int maxArea = 0;
        while(left < right)
        {
            maxArea = max(maxArea, (right - left) * min(height[right], height[left]));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};