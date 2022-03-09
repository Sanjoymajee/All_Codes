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
    void dfs(TreeNode* root,set<int>&s){
        if(!root)return;
        s.insert(root->val);
        if(s.size()>2){
            s.erase(--s.end());
        }
        dfs(root->left,s);
        dfs(root->right,s);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int>s;
        dfs(root,s);
        if(s.size()==1)return -1;
        int ans=0;
        if(s.size()){
            auto a=--s.end();
            ans=(*a);
        }
        return ans;
        
    }
};