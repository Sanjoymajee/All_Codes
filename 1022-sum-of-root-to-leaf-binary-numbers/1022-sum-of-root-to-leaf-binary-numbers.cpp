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
    int sum=0;
    int biTodec(string s){
        reverse(s.begin(),s.end());
        int sm=0;
        int p=1;
        for(int i=0;i<s.size();i++){
            sm+=(s[i]-'0')*p;
            p*=2;
        }
        return sm;
    }
    
    void help(TreeNode* root,string s){
        if(!root)return;
        s+=root->val+'0';
        if(root->left==root->right){
            sum+=biTodec(s);
            return;
        }
        help(root->left,s);
        help(root->right,s);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        help(root,"");
        return sum;
    }
};