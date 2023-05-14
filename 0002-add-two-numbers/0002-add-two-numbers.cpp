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
        ListNode * head = new ListNode();
        ListNode * temp = head;
        int carry = 0;
        
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            if(val>9) {
                carry=1;
                val=val-10;
            }
            else carry =0;
            ListNode * t = new ListNode(val);
            temp->next = t;
            temp = t;
            
            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        while(l1){
            int val = l1->val + carry;
            if(val>9){
                carry=1;
                val = val-10;
            }
            else carry=0;
            ListNode * t1 = new ListNode(val);
            temp->next = t1;
            temp = t1;
            l1=l1->next;
        }
        
        while(l2){
            int val = l2->val + carry;
            if(val>9){
                carry=1;
                val = val-10;
            }
            else carry = 0;
            ListNode * t2 = new ListNode(val);
            temp->next = t2;
            temp = t2;
            l2 = l2->next;
        }
        if (carry){
            ListNode * t3 = new ListNode(carry);
            temp->next = t3;
            temp = t3;
            
        }        
        
        return head->next;
        
        
        
    }
};