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
    int height(Node* root){
        if(!root)return 0;
        vector<Node*>A=root->children;
        int res=1;
        for(auto a:A){
            res=max(1+height(a),res);
        }
        return res;
    }
    
    int maxDepth(Node* root) {
        int h=height(root);
        return h;
    }
};