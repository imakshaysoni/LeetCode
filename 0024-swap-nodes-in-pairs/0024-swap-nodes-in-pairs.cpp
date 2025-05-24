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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* newHead = head->next;
        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* prev = NULL;
        while(curr and next){
            curr->next = next->next;
            next->next = curr;

            if(prev!=NULL) prev->next = next;
            prev=curr;
            
            curr = curr->next;
            if(curr) next = curr->next;

        }

        return newHead;
    }
};