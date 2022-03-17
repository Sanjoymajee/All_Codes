/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    stack<int>st;
    
    int length(ListNode* head){
        int sz=0;
        while(head){
            sz++;
            head=head->next;
        }
        return sz;
    }
    
    void dfs(ListNode* head,vector<int>&ans,int i){
        if(!head)return;
        dfs(head->next,ans,i+1);
        while(!st.empty() && head->val>=st.top())st.pop();
        if(!st.empty())ans[i]=st.top();
        st.push(head->val);
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head)return {};
        int len=length(head);
        vector<int>ans(len);
        dfs(head,ans,0);
        return ans;
    }
};