/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        
//         Hashing Method
//         unordered_set<ListNode*> s;
//         while (head!=NULL){
//             if(s.find(head)!=s.end()){
//                 return true;
//             }
//             s.insert(head);
//             head = head->next;           
            
            
//         }
//         return false;
        
//         Slow Pointer /Fast Pointer mehtod( Tortoise Mehtod)
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=NULL and fast->next!=NULL){     
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow) return true;      
        }
        return false;
        
    }
};