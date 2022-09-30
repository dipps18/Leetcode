class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int cur = startFuel;
        int stops = 0;
        priority_queue<int> pq;
        int i = 0;
        while(cur < target)
        {
            while(i < stations.size() && stations[i][0] <= cur)
                pq.push(stations[i++][1]);
            
            if(pq.empty()) return -1;
            cur += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};