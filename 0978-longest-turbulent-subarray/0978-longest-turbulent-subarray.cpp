class Solution {
public:
    int compare(int a, int b)
    {
        if(a < b)
        {
            return -1;
        }
        else if(a > b)
        {
            return 1;
        }
        else
            return 0;
    }
    
    int maxTurbulenceSize(vector<int>& arr) {
        int anchor = 0;
        int res = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            int c = compare(arr[i - 1], arr[i]);
            if(c == 0)
            {            
                anchor = i;
            }
            
            if(i == arr.size() - 1 || c * compare(arr[i], arr[i + 1]) != -1)
            {
                res = max(res, i - anchor + 1);
                anchor = i;
            }
        }
        
        return res;
    }
};