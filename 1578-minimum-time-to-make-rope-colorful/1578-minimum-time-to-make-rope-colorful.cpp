class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        char prevColor = colors[0];
        int prevTime = neededTime[0];
        for(int i = 1; i < colors.size(); i++)
        {
            if(prevColor == colors[i])
            {
                res += min(neededTime[i], prevTime);
                
                //Since the one with the higher time stays
                prevTime = max(neededTime[i], prevTime);
            }
            else
            {
                prevColor = colors[i];
                prevTime = neededTime[i];
            }
        }
        return res;
    }
};