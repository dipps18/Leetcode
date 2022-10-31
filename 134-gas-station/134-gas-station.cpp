class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& costs) {
        int curGas = 0;
        int sumGas = reduce(gas.begin(), gas.end());
        int sumCosts = reduce(costs.begin(), costs.end());
        if(sumCosts > sumGas) return -1;
        int res = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            curGas += gas[i] - costs[i];
            if(curGas < 0)
            {
                curGas = 0;
                res = i + 1;
            }
        }
        return res;
    }
};