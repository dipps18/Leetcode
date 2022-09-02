class Solution {
public:
    string longestPalindrome(string s) {
        int l, r;
        int maxL = 0, maxLen = 1;
        for(int i = 0; i < s.size(); i++)
        {
            r = i;
            while(r < s.size() && s[i] == s[r])
                r++;
            
            l = i - 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
            }
            if(r - l - 1 > maxLen)
            {
                maxL = l + 1;
                maxLen = r - l - 1;
            }
        }
        return s.substr(maxL, maxLen);
    }
};