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
    map<int,int>m;
    
    void dfs(TreeNode* root,int l){
        if(!root)return;
        m[l]+=root->val;
        dfs(root->left,l+1);
        dfs(root->right,l+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        auto it=m.end();
        return (--it)->second;
    }
};