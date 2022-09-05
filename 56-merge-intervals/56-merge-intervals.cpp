class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());
        for(vector<int> interval : intervals)
        {
            if(output.empty() || output.back()[1] < interval[0])
                output.push_back(interval);
            else
                output.back()[1] = max(output.back()[1], interval[1]);
        }
        return output;
    }
    
};