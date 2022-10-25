class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curVector;
        vector<vector<int>> res = {{}};
        dfs(nums, curVector, res, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& curVector, vector<vector<int>>& res, int index)
    {
        if(index >= nums.size()) return;
        curVector.push_back(nums[index]);
        res.push_back(curVector);
        dfs(nums, curVector, res, index + 1);
        curVector.pop_back();
        dfs(nums, curVector, res, index + 1);
    }
};