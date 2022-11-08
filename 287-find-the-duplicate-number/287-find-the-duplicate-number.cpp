class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(fast == 0 || fast != slow)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        
        slow = 0;
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};