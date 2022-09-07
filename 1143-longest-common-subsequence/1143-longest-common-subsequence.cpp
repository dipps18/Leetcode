class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        vector<int> cur(t2.size() + 1, 0), prev(t2.size() + 1, 0);
        for(int i = 1; i <= t1.size(); i++)
        {
            for(int j = 1; j <= t2.size(); j++)
            {
                if(t1[i - 1] == t2[j - 1])
                    cur[j] = max(cur[j - 1], prev[j - 1] + 1);
                else
                    cur[j] = max(cur[j - 1], prev[j]);
            }
            swap(cur, prev);
        }
        return prev[t2.size()];
    }
};


