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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        while(l1 and l2){
            int val1 = l1->val;
            int val2 = l2->val;
            int sum = carry + val1 + val2;
            ans->next = new ListNode(sum%10);

            carry = sum/10;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            ans->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            ans = ans->next;
        }
        while(l2){
            int sum = l2->val + carry;
            ans->next = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next;
            ans = ans->next;
        }
        if(carry!=0){
            ans->next = new ListNode(carry);
        }
        return head->next;
        
    }
};