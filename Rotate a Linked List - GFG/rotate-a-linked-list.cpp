// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    // int length(Node* head){
    //     int sz=0;
    //     while(head){
    //         sz++;
    //         head=head->next;
    //     }
    //     return sz;
    // }
    
    Node* rotate(Node* head, int k){
        if(!head)return head;
        Node* temp=head;
        // int l=length(head);
        Node* last=head;
        while(last->next)last=last->next;
        k--;
        while(k--)temp=temp->next;
        if(temp==last)return head;
        Node* t=head;
        head=temp->next;
        temp->next=NULL;
        last->next=t;
        return head;
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends