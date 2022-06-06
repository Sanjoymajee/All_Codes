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
    vector<int>inorder;
    
    void inorderTrv(TreeNode* root){
        if(!root)return;
        inorderTrv(root->left);
        inorder.push_back(root->val);
        inorderTrv(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorderTrv(root);
        // for(auto a:inorder)cout<<a;
        for(int i=0;i<inorder.size();i++){
            int val = k - inorder[i];
            int sVal = lower_bound(inorder.begin(),inorder.end(),val) - inorder.begin();
            if(sVal == i || sVal == inorder.size())continue;
            if(inorder[sVal] == val)return true;
        }
        return false;
    }
};