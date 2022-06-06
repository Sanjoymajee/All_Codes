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
    TreeNode* help(TreeNode* root,int val){
        TreeNode* node = new TreeNode(val);
        if(!root){
            return node;
        }
        if(root->val > val)root->left = help(root->left,val);
        else root->right = help(root->right,val);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<n;i++){
            root = help(root,preorder[i]);
        }
        return root;
    }
};