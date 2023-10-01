class Solution {
public:
    int longestBeautifulSubstring(string word) {
        if(word.size() < 5) return 0;
        
        int l = 1, r = 1;
        int currentCount = 1, maxCount = 0;
        int differentCharCount = 1;
        
        while(r < word.length())
        {
            if(word[r] >= word[r - 1])
            {
                if(word[r] != word[r - 1])
                    differentCharCount++;
                currentCount++;
            }
            else
            {
                if(differentCharCount == 5)
                    maxCount = max(currentCount, maxCount);
                currentCount = 1;
                differentCharCount = 1;
                while(word[r] != 'a' && r < word.length())
                    r++;
                l = r;
            }
            r++;
        }
        if(differentCharCount == 5)
            maxCount = max(currentCount, maxCount);
        return maxCount;
    }
};