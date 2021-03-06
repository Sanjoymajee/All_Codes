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
    
    void dfs(TreeNode* root,vector<int>&v){
        v.push_back(root->val);
        if(root->left)dfs(root->left,v);
        if(root->right)dfs(root->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int>v;
        dfs(root,v);
        return v;
    }
};