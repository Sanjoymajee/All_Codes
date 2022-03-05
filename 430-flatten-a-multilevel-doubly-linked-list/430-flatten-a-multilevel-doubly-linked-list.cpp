/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void dfs(Node* head,vector<Node*>&v){
        v.push_back(head);
        if(head->child){
            dfs(head->child,v);
        }
        head->child=NULL;
        if(head->next){
            dfs(head->next,v);
        }
    }
    
    Node* flatten(Node* head) {
        if(!head)return head;
        vector<Node*>v;
        dfs(head,v);
        int n=v.size();
        if(n==1){
            v[0]->next=NULL;
            v[0]->prev=NULL;
            return v[0];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                v[i]->prev=NULL;
                v[i]->next=v[i+1];
                continue;
            }
            if(i==n-1){
                v[i]->next=NULL;
                v[i]->prev=v[i-1];
                continue;
            }
            v[i]->next=v[i+1];
            v[i]->prev=v[i-1];
        }
        return v[0];
    }
};