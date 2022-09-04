class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> added;
        int cc = 0;
        queue<int> amounts;
        amounts.push(0);
        while(!amounts.empty())
        {
            int n = amounts.size();
            for(int i = 0; i < n; i++)
            {      
                int cur = amounts.front();
                amounts.pop();
                if(cur == amount) return cc;
                if(added.insert(cur).second == false || cur > amount) continue;
                for(int c : coins) 
                    if(c <= amount && c + cur <= amount)
                        amounts.push(c + cur);
            }
            cc++;
        }
        return -1;
    }

};