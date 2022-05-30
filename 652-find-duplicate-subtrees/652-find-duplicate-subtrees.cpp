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
    string dfs(TreeNode* r, unordered_map<string,int> &m, vector<TreeNode* >&tmp){
        if(!r)return "";
        string s= to_string(r->val)+ "-" + dfs(r->left,m,tmp) + "-" + dfs(r->right,m,tmp) ;
        if(m[s]==1)tmp.push_back(r);
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode* >tmp;
        dfs(root,m,tmp);
        return tmp;
    }
};