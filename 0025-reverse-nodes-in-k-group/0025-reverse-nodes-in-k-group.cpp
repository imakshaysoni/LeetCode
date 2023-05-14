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
//         Iterative Approch
        if(head==NULL || head->next==NULL ||k==1) return head;
        ListNode * dummy = new ListNode(-1);
        ListNode * beforeStart = dummy;
        beforeStart->next = head;
        ListNode * start = head;
        ListNode * end = head;
        int i=0;
        while(end!=NULL){
            i++;
            if(i%k==0){
                ListNode * start = beforeStart->next;
                ListNode * temp = end->next;
                reverseList(start, end);
                beforeStart->next = end;
                start->next = temp;
                beforeStart= start;
                end = temp;
            }
            else{
                end = end->next;
            }
            
            
        }
        
        return dummy->next;
        
        
        
//         Recursive Approch, TC O(N) && SC =O(n/k) 
//         if(head==NULL || head->next==NULL || k==1) return head;
//         ListNode * start = head;
//         ListNode * end = head;
        
//         for(int i=1;i<k;i++) {
//             end = end->next;
//             if(end==NULL) return head;
            
//         }        
//         ListNode * nextHead = reverseKGroup(end->next,k);
//         reverseList(start, end);
//         start->next = nextHead;
//         return end;
        
    }
    
    void reverseList(ListNode * start, ListNode * end){
        ListNode * prev = NULL;
        ListNode * curr = start;
        while(prev!=end){
            ListNode * temp = curr->next;
            curr->next = prev;
            prev = curr;
            if(temp) curr = temp;            
        }     
    }
};