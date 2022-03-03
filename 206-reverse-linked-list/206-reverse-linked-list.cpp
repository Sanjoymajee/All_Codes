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
    ListNode* temp;
    
    ListNode* help(ListNode* head){
        if(!head->next){
            temp=head;
            return temp;
        }
        ListNode* node=help(head->next);
        node->next=head;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* node=help(head);
        node->next=NULL;
        head=temp;
        return head;
    }
};