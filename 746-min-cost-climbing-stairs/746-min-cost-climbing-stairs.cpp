class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int next = 0, next_two = 0, cur = INT_MAX;
        for(int i = cost.size() - 1; i >= 0; i--)
        {
            cur = min(next, next_two) + cost[i];
            swap(next_two, next);
            swap(cur, next);
        }
        return min(next, next_two);
    }
};