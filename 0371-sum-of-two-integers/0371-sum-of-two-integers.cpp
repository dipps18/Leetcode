class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        while(a != 0)
        {
            c = a&b;
            b ^= a;
            a = c << 1;
        }
        return b;
    }
};



