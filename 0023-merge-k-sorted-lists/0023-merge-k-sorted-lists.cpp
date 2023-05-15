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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        
        ListNode *first = lists[0];
        for(int i=1;i<lists.size();i++){
            ListNode * second = lists[i];
            first =  mergeSorted(first, second);          
        }
        return first;        
        
    }
    
    ListNode * mergeSorted(ListNode *a, ListNode * b){
        ListNode * dummy = new ListNode(-1);
        ListNode * temp = dummy;
        while(a && b){
            if(a->val < b->val){
                temp->next = a;
                a = a->next;
            }
            else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        
        if(a) temp->next =a;
        if(b) temp->next = b;
        
        return dummy->next;
        
    }
};