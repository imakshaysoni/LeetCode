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
//         Brute Force, Store the values of linked list in str and check it is palindrome or not
        // string s="";
        // ListNode *curr = head;
        // while(curr){
        //     s+=to_string(curr->val);
        //     curr = curr->next;
        // }
        // // cout<<s;
        // int n=s.size();
        // for(int i=0;i<n/2;i++){
        //     if(s[i]!=s[n-i-1]) return false;
        // }
        // return true;
        
//         Find Middle & And Reverse 2nd Half and compare second half & first half
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
//         Slow is now the 1st middle
        ListNode * head2 = reverseLinkList(slow->next);
        slow->next = head2;
        slow = slow->next;
        ListNode * dummy = head;
        while(slow){
            if(dummy->val != slow->val) return false;
            slow = slow->next;
            dummy = dummy->next;
        }
        return true;
        
        
    }
    
    ListNode * reverseLinkList(ListNode *head){
        ListNode * prev = NULL;
        while(head){
            ListNode * temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;          
        }
        return prev;
        
    }
};