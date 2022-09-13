class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> needed(26,0);
        int count = 0;
        int m = s1.size(), n = s2.size(); 
        int left = 0, right = 0;
        for(int i = 0; i < m; i++)
            needed[s1[i] - 'a']++;
        
        while(right < n)
        {
            if(needed[s2[right] - 'a'] != 0)
            {
                needed[s2[right] - 'a']--;
                right++;
                count++;
            }
            else if(count > 0)
            {
                count--;
                needed[s2[left] - 'a']++;
                left++;
            }
            else
            {
                right++;
                left++;
            }
            if(count == m) return true;
        }
        return false;
    }
};