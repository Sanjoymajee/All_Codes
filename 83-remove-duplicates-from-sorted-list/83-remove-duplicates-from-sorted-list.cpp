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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* node=head;
        ListNode* temp=head->next;
        while(temp){
            if(temp->val!=node->val){
                node=temp;
                temp=temp->next;
            }
            else{
                node->next=temp->next;
                temp=temp->next;
            }
        }
        return head;
    }
};