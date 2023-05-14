//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node * newHead = reverse(head);
        Node * temp = newHead;
        Node * prev = newHead;
        temp->data = temp->data+1;
        int carry=0;
        while(temp and (temp->data>9 || carry)){
            temp->data = temp->data+carry;
            carry = temp->data/10;
            temp->data = temp->data%10;
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL and carry){
            Node* n = new Node(carry);
            prev->next=n;
        }
        
        return reverse(newHead);
        
    }
    Node * reverse(Node * head){
        Node * prev=NULL;
        while(head){
            Node * next = head->next;
            head->next= prev;
            prev = head;
            head=next;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends