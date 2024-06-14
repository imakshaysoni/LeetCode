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
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* new_rev = reverse_link_list(slow);
        ListNode* mid = new_rev;
        
        ListNode* dummy = head;
        while(new_rev and dummy){
            ListNode* temp = dummy->next;
            dummy->next = new_rev;
            new_rev = new_rev->next;
            dummy->next->next = temp;
            dummy = temp;
        }
        if (dummy){
            dummy->next = new_rev;
        }
            
        
        
    }
    
    ListNode* reverse_link_list(ListNode * head){
        ListNode* dummy = head;
        ListNode * prev = NULL;
        while(dummy){
            ListNode* temp = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = temp;
        }
        return prev;
    }
        
        
     
};