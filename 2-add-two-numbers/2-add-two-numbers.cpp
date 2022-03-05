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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* head=new ListNode(0);
        int carry=0;
        ListNode* temp=head;
        while(p1 && p2){
            carry+=p1->val+p2->val;
            ListNode* node=new ListNode(carry%10);
            carry/=10;
            p1=p1->next;
            p2=p2->next;
            temp->next=node;
            temp=temp->next;
        }
        while(p1){
            carry+=p1->val;
            ListNode* node=new ListNode(carry%10);
            carry/=10;
            p1=p1->next;
            temp->next=node;
            temp=temp->next;
        }
        while(p2){
            carry+=p2->val;
            ListNode* node=new ListNode(carry%10);
            carry/=10;
            p2=p2->next;
            temp->next=node;
            temp=temp->next;
        }
        if(carry){
            ListNode* node=new ListNode(carry);
            temp->next=node;
        }
        return head->next;
    }
};