class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> newIntervals;
        for(int i = 0; i < intervals.size();i++)
        {
            if(newIntervals.empty() || intervals[i][0] >= newIntervals.back()[1])
            {
                newIntervals.push_back(intervals[i]);
            }
            else if(intervals[i][0] < newIntervals.back()[1])
            {
                newIntervals.back()[1] = min(intervals[i][1], newIntervals.back()[1]);
            }
        }
        return intervals.size() - newIntervals.size();
    }
};