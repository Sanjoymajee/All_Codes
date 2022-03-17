/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1=headA;
        ListNode* t2=headB;
        int sz1=0,sz2=0;
        while(t1){
            sz1++;
            t1=t1->next;
        }
        while(t2){
            sz2++;
            t2=t2->next;
        }
        if(sz1<sz2)return getIntersectionNode(headB,headA);
        int diff=sz1-sz2;
        t1=headA;
        t2=headB;
        while(diff--)t1=t1->next;
        while(t1 && t2){
            if(t1==t2)return t1;
            t1=t1->next;
            t2=t2->next;
        }
        return NULL;
    }
};