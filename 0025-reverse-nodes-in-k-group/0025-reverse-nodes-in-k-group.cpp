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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        ListNode * start = head;
        ListNode * end = head;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        for(int i=0;i<k-1;i++) {
            end = end->next;
            if(end==NULL) return head;
            
        }
        // cout<<start->val<<" "<<end->val<<endl;
        
        ListNode * nextHead = reverseKGroup(end->next,k);
        // cout<<end->val;
        reverseL(start, end);
        start->next = nextHead;
        return end;
        
    }
    
    void reverseL(ListNode * s, ListNode * e){
	ListNode *p=NULL, *c = s, *n = s->next;
	while(p!=e){
		c->next = p;
		p=c;
		c=n;
		if(n!=NULL) n = n->next;
	}
    }
    
    // ListNode * reverseList(ListNode * start, ListNode * end){
    //     ListNode * prev = NULL;
    //     while(start!=end){
    //         ListNode * temp = start->next;
    //         start->next = prev;
    //         prev = start;
    //         if(temp) start = temp;            
    //     }     
    //     return start;
    // }
};