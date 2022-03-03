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
    
    bool help(ListNode* node){
        if(node==NULL)return true;
        bool ok=help(node->next) && (node->val == temp->val);
        temp=temp->next;
        return ok;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        temp=head;
        return help(head);
    }
};