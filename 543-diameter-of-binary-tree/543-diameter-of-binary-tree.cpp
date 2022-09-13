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
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        helper(root, diam);
        return diam;
    }
    
    int helper(TreeNode* root, int& diam)
    {
        int left = 0, right = 0;
        if(root->left)
            left = helper(root->left, diam) + 1;
        if(root->right)
            right = helper(root->right, diam) + 1;
        diam = max(diam, left + right);
        return max(left, right);
    }
};