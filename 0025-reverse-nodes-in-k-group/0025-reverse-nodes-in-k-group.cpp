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
    ListNode* reverseKGroup(ListNode *head, int k) {
        int count = 0;
		ListNode * curr = head;
		
		// to check - if set is having more than k elements , otherwise return head
		while (count != k) {
			if (curr == NULL) {
				return head;
			}
			curr = curr->next;
			count++;
		}

		// to find reverse if we have k elements in set
		curr = head;
		ListNode * prev = NULL;
		count = 0;
		ListNode * next = NULL;
		while (count != k) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		
		//assign head of this set to next set prev
		if (next != NULL) {
			head->next = reverseKGroup(next, k);
		}

		return prev;
    }
};