class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        struct
        {
            bool operator()(const vector<int> l, const vector<int> r) const 
            { 
                return sqrt(pow(l[0], 2) + pow(l[1], 2)) > sqrt(pow(r[0], 2) + pow(r[1], 2)); 
            }
        } comp;
        std::priority_queue queue(points.begin(), points.end(), comp);
        for(int i = 0; i < k; i++)
        {
            result.push_back(queue.top());
            queue.pop();
        }
        return result;
    }
};