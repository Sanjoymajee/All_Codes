/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*,Node*>m;
    
    Node* dfs(Node* head){
        if(!head)return NULL;
        Node* node=new Node(head->val);
        m[head]=node;
        node->next=dfs(head->next);
        node->random=m[head->random];
        return node;
    }
    
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* node = dfs(head);
        return node;
    }
};