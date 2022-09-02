class Solution {
public:
    int countSubstrings(string s) {
        int l, r, count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            r = i;
            while(r < s.size() && s[i] == s[r])
            {
                r++;
                count++;
            }
            
            l = i - 1;
            while(l >= 0 && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};