/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> dict;
        return dfs(root, dict, k);   
    }
    
    bool dfs(TreeNode* root, unordered_map<int, int>& dict, int& k)
    {
        if(root == nullptr) return false;
        if(dict[k - root->val]) return true;
        dict[root->val]++;
        return dfs(root->right, dict, k) || dfs(root->left, dict, k);
    }
};