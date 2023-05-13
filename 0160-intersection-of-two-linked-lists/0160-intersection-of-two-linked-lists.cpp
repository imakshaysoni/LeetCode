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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        
        ListNode * first = headA;
        ListNode * second = headB;
        while(first!=second){
            if(!first) first = headB;
            else first = first->next;
            if(!second) second = headA;
            else second = second->next;            
        }
        return first;
        
        
//         Brute Force, time: O(n+m), space o(n)
//         unordered_set<ListNode*> set;
//         while(headA){
//             set.insert(headA);
//             headA = headA->next;
//         }
        
//         while(headB){
//             if(set.find(headB)!=set.end()){
//                 return headB;
//             }
//             headB = headB->next;
//         }
        
//         return 0;
        
        
    }
};