class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] >= end)
                end = intervals[i][1];
            
            else if(intervals[i][0] < end)
            {
                count++;
                end = min(intervals[i][1], end);
            }
        }
        return count;
    }
};