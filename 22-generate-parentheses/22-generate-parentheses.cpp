class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curString(2*n, '(');
        vector<string> res;
        dfs(curString, res, 1, 0, n);
        return res;
    }
    
    void dfs(string& curString, vector<string>& res, int open, int close, int& n)
    {
        if(open + close == 2 * n)
        {
            res.push_back(curString);
            return;
            
        }
        if(open < n)
        {
            curString[open + close] = '(';
            dfs(curString, res, open + 1, close, n);
        }
        if(close < open)
        {
            curString[open + close] = ')';
            dfs(curString, res, open, close + 1, n);
        }
    }
};