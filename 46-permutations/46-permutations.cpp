class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> curSet;
        vector<int> curVector;
        dfs(nums, res, curSet, curVector);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, unordered_set<int>& curSet, vector<int>&curVector)
    {
        if(curSet.size() == nums.size())
        {
            res.push_back(curVector);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(curSet.insert(nums[i]).second == true)
            {
                curVector.push_back(nums[i]);
                dfs(nums, res, curSet, curVector);
                curSet.erase(nums[i]);
                curVector.pop_back();

            }
        }
    }
};