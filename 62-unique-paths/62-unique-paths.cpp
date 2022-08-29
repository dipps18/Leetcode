/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        return uniquePaths(m - 1 , n) + uniquePaths(m , n - 1); // too slow
    }
};
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> col(n, 1), prevRow(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                col[j] = col[j - 1] + prevRow[j];
            }
            cout << endl;
            swap(col, prevRow);
        }
        return prevRow[n - 1];
    }
};