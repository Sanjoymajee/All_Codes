/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>v;
    vector<int> preorder(Node* root) {
        if(!root)return v;
        vector<Node*>A=root->children;
        int n=A.size();
        v.push_back(root->val);
        for(int i=0;i<n;i++){
            preorder(A[i]);
        }
        return v;
    }
};