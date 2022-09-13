class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> output;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(nums[i] > 0) return output;
            for(int j = i + 1; j < nums.size() - 1; j++)
            {
                int desired = -(nums[i] + nums[j]);
                if(mp.find(desired) != mp.end() && mp[desired] > j)
                {
                    output.push_back({nums[i], nums[j], desired});
                    j = mp[nums[j]];
                }
            }
            if(mp.find(nums[i]) != mp.end()) i = mp[nums[i]];
        }
        return output;
    }
};
