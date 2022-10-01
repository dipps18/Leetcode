class Solution {
public:
    int numDecodings(string s) {
        int cur, next = 1, next_two = 1;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            cur = s[i] != '0' ? next : 0;
            if(i + 1 < s.size() && ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1'))
                cur += next_two;
            next_two = next;
            next = cur;
        }
        return cur;
    }
};