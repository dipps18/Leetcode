class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) return "";
        bool differ = false;
        int i = 0;
        while(i < palindrome.size() && palindrome[i] == 'a')
            i++;
        int j = i + 1;
        while(!differ && j < n)
        {
            if(palindrome[j++] != 'a')
                differ = true;
        }
        if(i >= palindrome.size() || !differ) 
            palindrome[n - 1]++;
        else
            palindrome[i] = 'a';
        return palindrome;
    }
};