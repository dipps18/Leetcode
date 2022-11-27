class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), curIdx = 0, added = 0, res = 0;
        vector<bool>visited(n);
        priority_queue<pair<int, int>> pq;
        while(added < n - 1)
        {
            visited[curIdx] = true;
            added++;
            for(int i = 0; i < n; i++)
            {
                int cost = abs(points[i][0] - points[curIdx][0]) + abs(points[i][1] - points[curIdx][1]);
                if(!visited[i])
                    pq.push({-cost, i});
            }
            while(visited[pq.top().second])
                pq.pop();
            res -= pq.top().first;
            curIdx = pq.top().second;
            pq.pop();        
        }
        return res;
    }
};