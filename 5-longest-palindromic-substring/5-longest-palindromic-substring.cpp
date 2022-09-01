class Solution {
public:
    string longestPalindrome(string s) {
        string output;
        int m = s.size();
        vector<vector<bool>> visited(m, vector<bool>(m, false));
        int maxL = m/2, maxR = m/2;
        helper(s, m/2 - 1, m/2, maxL, maxR, visited);
        output = s.substr(maxL, maxR - maxL + 1);
        return output;
    }
    
    void helper(string& s, int l, int r, int& maxL, int& maxR, vector<vector<bool>>& visited)
    {
        if(l < 0 || r >= s.size()) return;
        if(visited[l][r]) return;
        visited[l][r] = true;
        if(s[l] == s[r])
        {
            if(r - l > maxR - maxL)
            {
                maxR = r;
                maxL = l;
            }
            helper(s, l - 1, r + 1, maxL, maxR, visited);
        }
        helper(s, l, l + 1, maxL, maxR, visited);
        helper(s, l - 1, l + 1, maxL, maxR, visited);
        helper(s, r, r + 1, maxL, maxR, visited);
        helper(s, r - 1, r + 1, maxL, maxR, visited);
    }
};