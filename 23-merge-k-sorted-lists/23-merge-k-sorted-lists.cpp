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
    ListNode* help(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        if(list1->val<list2->val){
            list1->next=help(list1->next,list2);
            return list1;
        }
        else{
            list2->next=help(list1,list2->next);
            return list2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(INT_MIN);
        for(int i=0;i<lists.size();i++){
            head=help(head,lists[i]);
        }
        return head->next;
    }
};