class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 1) return;
        int n = matrix.size();
        vector<int> l1 = {0, 0};
        vector<int> l2 = {0, n - 1};
        vector<int> l3 = {n - 1, n - 1};
        vector<int> l4 = {n - 1, 0};

        helper(matrix, l1, l2, l3, l4, n - 1);
    }
    
    void helper(vector<vector<int>>& matrix, vector<int>& l1, vector<int>& l2, vector<int>& l3, vector<int>& l4, int boundary)
    {

        int temp; 
        if(l1[1] == boundary){
            boundary -= 1;
            swap(l4, l1);
            swap(l4, l2);
            swap(l4, l3);
            l1 = {l1[0] + 1, l1[1] + 1};
            l2 = {l2[0] + 1, l2[1] - 1};
            l3 = {l3[0] - 1, l3[1] - 1};
            l4 = {l4[0] - 1, l4[1] + 1};
        }
        temp = matrix[l2[0]][l2[1]];
        if(l1[0] == l2[0] && l1[1] == l2[1]) return;
        matrix[l2[0]][l2[1]] = matrix[l1[0]][l1[1]];
        swap(matrix[l3[0]][l3[1]], temp);
        swap(matrix[l4[0]][l4[1]], temp);
        swap(matrix[l1[0]][l1[1]], temp);
        if((l1[0] == l2[0] && l1[1] + 1 == l2[1]) || (l1[1] == l2[1] && l1[0] + 1 == l2[0])) return; 
        l1[1] += 1; l2[0] += 1;
        l3[1] -= 1; l4[0] -= 1;
        helper(matrix, l1, l2, l3, l4, boundary);
        
    }
};