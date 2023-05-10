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
    void deleteNode(ListNode* node) {
//         We are not given access to node, so we swap value to next node & delete next node
        swap(node->val, node->next->val);
        ListNode *temp = node->next;
        node->next= temp->next;
        delete temp;
        
    }
};