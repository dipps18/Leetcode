class Solution {
public:
    double myPow(double x, int n) {
        double res;
        if(n == 0) return 1;
        if(n == 1)
            return x;
        if(n == -1) 
            return 1/x;
        if(n % 2 == 0)
        {
            res = myPow(x, n/2);
            return res * res;
        }
        else
        {
            if(n > 0)
            {
                res = x * myPow(x, n/2);
                return res * res/x;
            }
            else
            {
                res = 1/x * myPow(x, n/2);
                return res * res * x;
            }
        }
    }
};