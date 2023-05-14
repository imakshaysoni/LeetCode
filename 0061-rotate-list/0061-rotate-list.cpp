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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode * temp = head;
        int count=1;
        while(temp->next){
            count++;
            temp = temp->next;
        }
        cout<<count;
        if(k>=count){
            k=k%count;
            if(k==0) return head;
        }
        temp->next = head;
        int n = count-k;
        ListNode * first = head;
        for(int i=1;i<n;i++){
            first = first->next;
        }
        head = first->next;
        first->next = NULL;
        return head;
        
        
        
        
        
//         Mylogic 99% correct and working well, Just got one more optimization
        // if(head==NULL || head->next==NULL || k==0) return head;
        // ListNode * temp = head;
        // int count=0;
        // while(temp){
        //     count++;
        //     temp = temp->next;
        // }
        // if(k>count){
        //     k=k%count;
        //     if(k==0) return head;
        // }
        // ListNode * first = head;
        // ListNode * second = head;
        // for(int i=0;i<k;i++){
        //     second = second->next;
        //     if(second==NULL) return head;
        // }
        // // cout<<second->val;
        // while(second->next){
        //     second=second->next;
        //     first = first->next;
        // }
        // ListNode * newHead = first->next;
        // first->next = NULL;
        // second->next = head;
        // return newHead;
    }
};