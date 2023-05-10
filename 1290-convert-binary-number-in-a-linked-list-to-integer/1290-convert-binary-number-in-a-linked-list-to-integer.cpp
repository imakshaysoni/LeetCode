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
    int getDecimalValue(ListNode* head) {
        ListNode * temp = head;
        int num=0;
        while(temp!=NULL){
            num=num*2 + temp->val;
            temp = temp->next;
        }
        
        return num;
        
        
    }
    int binaryToDecimal(int n)
            {
                int num = n;
                int dec_value = 0;

                // Initializing base value to 1, i.e 2^0
                int base = 1;

                int temp = num;
                while (temp) {
                    int last_digit = temp % 10;
                    temp = temp / 10;

                    dec_value += last_digit * base;

                    base = base * 2;
                }

                return dec_value;
            }
};