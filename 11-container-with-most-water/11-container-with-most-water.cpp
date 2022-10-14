class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), left = 0, right = n - 1;
        int maxArea = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                maxArea = max(maxArea, (right - left)*height[left]);
                left++;
            }
            else
            {
                maxArea = max(maxArea, (right - left)*height[right]);
                right--;
            }
        }
        return maxArea;
    }
};