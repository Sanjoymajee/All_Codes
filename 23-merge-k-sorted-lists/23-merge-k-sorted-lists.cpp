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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        if(!list1 || !list2){
            return (list1)?list1:list2;
        }
        ListNode* it1=list1;
        ListNode* it2=list2;
        if(it1->val<=it2->val){
            head=it1;
            it1=it1->next;
        }
        else{
            head=it2;
            it2=it2->next;
        }
        ListNode* node=head;
        while(it1 && it2){
            if(it1->val<=it2->val){
                node->next=it1;
                it1=it1->next;
            }
            else{
                node->next=it2;
                it2=it2->next;
            }
            node=node->next;
        }
        while(it1){
            node->next=it1;
            it1=it1->next;
            node=node->next;
        }
        while(it2){
            node->next=it2;
            it2=it2->next;
            node=node->next;
        }
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(INT_MIN);
        for(int i=0;i<lists.size();i++){
            head=mergeTwoLists(head,lists[i]);
        }
        return head->next;
    }
};