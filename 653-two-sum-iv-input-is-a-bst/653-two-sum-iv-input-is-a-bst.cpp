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
        unordered_set<int> set;
        return dfs(root, set, k);   
    }
    
    bool dfs(TreeNode* &root, unordered_set<int>& set, int& k)
    {
        if(root == nullptr) return false;
        if(set.find(k - root->val) != set.end()) return true;
        set.insert(root->val);
        return dfs(root->right, set, k) || dfs(root->left, set, k);
    }
};