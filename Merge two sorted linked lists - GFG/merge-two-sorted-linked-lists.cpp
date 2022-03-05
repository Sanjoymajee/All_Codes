// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* list1, Node* list2)  
{  
    Node* head;
    if(!list1 || !list2){
        return (list1)?list1:list2;
    }
    Node* it1=list1;
    Node* it2=list2;
    if(it1->data<=it2->data){
        head=it1;
        it1=it1->next;
    }
    else{
        head=it2;
        it2=it2->next;
    }
    Node* node=head;
    while(it1 && it2){
        if(it1->data<=it2->data){
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