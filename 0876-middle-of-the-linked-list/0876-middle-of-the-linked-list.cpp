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
    ListNode* middleNode(ListNode* head) {
        
//         Approch First Find the length of Linked List
        int count=0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        cout<<count;
        temp = head;
        count = count/2+1;
        while(count>1){
            temp= temp->next;
            count--;
        }
        return temp;
    }
    
//     
    
};

// Another Approch find in Disucssion Section
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode *slow = head, *fast = head;
//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
// };