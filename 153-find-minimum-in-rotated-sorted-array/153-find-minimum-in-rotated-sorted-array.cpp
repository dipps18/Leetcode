class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int res = INT_MAX;
        while(left <= right)
        {
            int mid = left + (right - left)/ 2;
            res = min(res, nums[mid]);
            
            //example [5, 1, 2, 3, 4]
            if(nums[mid] < nums[left] && nums[mid] < nums[right])
            {
                nums[left] > nums[right] ? right = mid - 1 : left = mid + 1;
            }
            else
            {
                nums[left] > nums[right] ? left = mid + 1 : right = mid -1;
            }
        }
        return res;
    }
};