class Solution {
public:
string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    vector<int> dict(128, 0), have(128, 0);
    queue<int> positions;
    string res = "";
    int right = 0, left = 0, count = 0, minL = -1, minR = s.size() - 1;
    for (char c : t)
        dict[c - 'A']++;
    
    while (right < s.size())
    {
        if (dict[s[right] - 'A'])
        {
            have[s[right] - 'A']++;
            if (have[s[right] - 'A'] <= dict[s[right] - 'A'])
                count++;
            if (left != right)
                positions.push(right);
            while (count == t.size())
            {
                if (minR - minL + 1 > right - left + 1)
                {
                    minL = left;
                    minR = right;
                }
                if (--have[s[left] - 'A'] < dict[s[left] - 'A'])
                    count--;
                if (!positions.empty())
                {
                    left = positions.front();
                    positions.pop();
                }
            }
        }
        if(!dict[s[left] - 'A']) left++;
        right++;
    }
    
    if(minL == -1) return "";
    for (int i = minL; i <= minR; i++)
        res += s[i];
    return res;
}
};