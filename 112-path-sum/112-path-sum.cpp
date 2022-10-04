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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
    
    bool dfs(TreeNode* root, int cur, int& target)
    {
        if(root == nullptr) return false;
        cur += root->val;
        if(cur == target && !root->left && !root->right) return true;
        return dfs(root->left, cur, target) || dfs(root->right, cur, target);
    }
    
};