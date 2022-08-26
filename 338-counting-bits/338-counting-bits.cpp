class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1, 0);
        for(int i = 0; i <= n; i++)
        {
            int cur = i;
            while(cur){
                cur = cur & cur - 1;
                output[i]++;
            }
        }
        return output;
    }
};