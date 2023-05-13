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
    ListNode *detectCycle(ListNode *head) {
        //         Hashing Method
//         unordered_set<ListNode*> s;
//         while (head!=NULL){
//             if(s.find(head)!=s.end()){
//                 return head;
//             }
//             s.insert(head);
//             head = head->next;           
            
            
//         }
//         return NULL;
        
        if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location
                // cout<<slow->val<<" "<<entry->val<<endl;
                slow  = slow->next;
                // cout<<slow->val<<endl;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;              
    }
};