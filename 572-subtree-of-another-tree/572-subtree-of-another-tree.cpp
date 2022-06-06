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

    bool help(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)return 1;
        if(!root)return 0;
        if(!subRoot)return 0;
        return ((root->val == subRoot->val) && help(root->left,subRoot->left) && 
                help(root->right,subRoot->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)return 1;
        if(!root)return 0;
        if(!subRoot)return 0;
        bool ok=false;
        if(root->val == subRoot->val)ok = help(root,subRoot);
        return ok || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};