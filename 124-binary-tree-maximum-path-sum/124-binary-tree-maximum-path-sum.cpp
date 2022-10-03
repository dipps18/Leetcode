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
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        int left = dfs(root->left, maxSum);
        int right = dfs(root->right, maxSum);
        int treeSum = max(max(root->val + left, root->val + right), root->val + left + right);
        return max(root->val, max(maxSum, treeSum));
    }
    
    int dfs(TreeNode* root, int& maxSum)
    {
        if(root == nullptr) return 0;
        int curSum = root->val;
        int l = dfs(root->left, maxSum);
        int r = dfs(root->right, maxSum);
        int childSum = max(l, r);
        int curSubMax = max(curSum + l + r, max(curSum, curSum + childSum));
        curSum = max(childSum + curSum, curSum);
        maxSum = max(max(curSubMax, curSum), maxSum);
        return max(curSum, 0);
    }
};