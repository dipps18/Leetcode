class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        bool pushed = false;
        if(intervals.empty()) return {newInterval};
        for(int i = 0; i < intervals.size(); i++)
        {
            if(newInterval[0] > intervals[i][0] && newInterval[0] > intervals[i][1])
                output.push_back(intervals[i]);
            else if(newInterval[0] < intervals[i][0] && newInterval[1] < intervals[i][0])
            {
                if(!pushed)
                {
                    output.push_back(newInterval);
                    pushed = true;
                }
                output.push_back(intervals[i]);
            }
            else
            {
                pushed = true;
                int s = min(intervals[i][0], newInterval[0]);
                int e = max(intervals[i][1], newInterval[1]);
                while(i < intervals.size())
                {
                    if(intervals[i][0] > e)
                    {
                        i--;
                        break;
                    }
                    if(e <= intervals[i][1])
                    {
                        e = max(e, intervals[i][1]);
                        break;
                    }
                    i++;
                }
                output.push_back({s, e});
            }
        }
        if(!pushed) output.push_back(newInterval);
        return output;
    }
};