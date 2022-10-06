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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        dfs(root, val, 1, depth);
        return root;
    }
    
    void dfs(TreeNode* &root, int val, int curDepth, int& targDepth)
    {
        if(root == nullptr) return;
        if(targDepth == 1)
        {
            root = new TreeNode(val, root, nullptr);
            return;
        }
        if(curDepth + 1 == targDepth)
        {
   
            TreeNode* right, *left;
            left = new TreeNode(val);
            left->left = root->left;
            right = new TreeNode(val);
            right->right = root->right;
            root->left = left;
            root->right = right;
            return;
        }
        dfs(root->left, val, curDepth + 1, targDepth);
        dfs(root->right, val, curDepth + 1, targDepth);
    }
};