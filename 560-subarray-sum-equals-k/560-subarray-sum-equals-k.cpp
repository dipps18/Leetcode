class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int output = 0;
        vector<int> prefix(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            prefix[i] += i == 0 ? nums[i] : prefix[i - 1] + nums[i];
            if(mp.find(prefix[i] - k) != mp.end()) output += mp[prefix[i] - k];
            if(prefix[i] == k) output++;
            mp[prefix[i]]++;
        }
        return output;
    }
};