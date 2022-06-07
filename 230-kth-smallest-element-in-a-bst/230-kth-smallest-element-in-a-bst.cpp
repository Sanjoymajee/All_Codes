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
    
    TreeNode* help(TreeNode* root,int k,int &i){
        if(!root)return root;
        TreeNode* ans = help(root->left,k,i);
        if(ans)return ans;
        if(i==k)return root;
        i++;
        return help(root->right,k,i);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int i=1;
        TreeNode* ans = help(root,k,i);
        return ans->val;
    }
};