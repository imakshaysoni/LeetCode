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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next==NULL and n==1) return NULL;
        
        ListNode * ptr = head;
        ListNode * ptr2 = head;
        while(n){
            ptr2 = ptr2->next;
            n--;
        }
        ListNode * prev = ptr;
        
        if(ptr2==NULL){
            head = head->next;
            return head;
        }
        while(ptr2){
            ptr2 = ptr2->next;
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        return head;        
        
        
    }
};