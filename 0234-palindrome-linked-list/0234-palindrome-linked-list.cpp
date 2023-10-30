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
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast =  head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev = reverseLinkedList(slow);
        ListNode *start = head;
        while(rev){
            if(start->val!=rev->val){
                return false;
            }
            rev = rev->next;
            start = start->next;
        }
        return true;      
        
        
    }
    ListNode* reverseLinkedList(ListNode* head){
        ListNode *temp = head;
        ListNode* prev = NULL;
        
        while(head){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;            
        }
        return prev;
    }
};