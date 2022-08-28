class Solution {
public:
    void sortDiag(vector<vector<int>>& mat, int x, int y) {
        vector<int> diag;
        int curX = x, curY = y;
        while(curX < mat.size() && curY < mat[0].size())
            diag.push_back(mat[curX++][curY++]);
        sort(diag.begin(), diag.end());
        curX = x, curY = y;
        for(auto elem : diag)
            mat[curX++][curY++] = elem;
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++) //sort starting from each row
            sortDiag(mat, i, 0);
        for(int i = 1; i < mat[0].size(); i++) //sort starting from each column
            sortDiag(mat, 0, i);
        return mat;
    }
};