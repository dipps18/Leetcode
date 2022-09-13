class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> dict(26, 0), needed(26,0);
        int count = 0;
        int m = s1.size(), n = s2.size(); 
        int left = 0, right = 0;
        for(int i = 0; i < m; i++)
        {
            dict[s1[i] - 'a']++;
            needed[s1[i] - 'a']++;
        }
        
        while(right < n)
        {
            if(needed[s2[right] - 'a'] != 0)
            {
                needed[s2[right] - 'a']--;
                right++;
                count++;
            }
            else
            {
                right = ++left;
                needed = dict;
                count = 0;
            }
            if(count == m) return true;
        }
        return false;
    }
};