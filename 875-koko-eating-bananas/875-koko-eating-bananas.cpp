class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        int lo = 1, hi;
        int res = INT_MAX;
        hi = *max_element(piles.begin(), piles.end());
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(canEatAll(h, mid, piles))
            {
                res = min(res, mid);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return res;
    }
    
    bool canEatAll(int time, int speed, vector<int>& piles)
    {
        int timeTaken = 0;
        for(int pile : piles)
        {
            if(pile > speed)
                timeTaken += (pile + speed - 1)/speed;
            else
                timeTaken += 1;
            if(timeTaken > time) return false;
        }
        return true;
    }
};