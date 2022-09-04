class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        int i = 0, start = newInterval[0], end = newInterval[1];
        while(i < intervals.size() && intervals[i][1] < newInterval[0])
            output.push_back(intervals[i++]);
        
        while(i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            start = min(start, intervals[i][0]);
            end = max(intervals[i++][1], end);   
        }
        
        output.push_back({start, end});
        while(i < intervals.size())
            output.push_back(intervals[i++]);
        
        return output;
    }
};