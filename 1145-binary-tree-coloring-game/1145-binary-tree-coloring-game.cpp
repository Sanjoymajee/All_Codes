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
    TreeNode* tar;
    void dfs(TreeNode* r,TreeNode* p,int x){
        if(!r)return;
        if(r->val==x){
            tar=r;
            return;
        }
        dfs(r->left,r,x);
        dfs(r->right,r,x);
    }

    int height(TreeNode* r){
        if(!r)return 0;
        int hl=height(r->left);
        int hr=height(r->right);
        return hl+hr+1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root->val==x){
            tar=root;
        }
        dfs(root->left,root,x);
        dfs(root->right,root,x);
        int t1=height(tar->left);
        int t2=height(tar->right);
        int t3=height(tar);
        if(t1>n/2 || t2>n/2 || (n-t3)>n/2)return true;
        return false;
    }
};