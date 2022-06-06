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
    int height(TreeNode* root){
        if(!root)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh,rh);
    }
    
    void dfs(TreeNode* root,vector<vector<int>>&ans,int level){
        if(!root)return;
        dfs(root->left,ans,level+1);
        dfs(root->right,ans,level+1);
        ans[level].push_back(root->val);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n= height(root);
        vector<vector<int>>ans(n);
        dfs(root,ans,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};