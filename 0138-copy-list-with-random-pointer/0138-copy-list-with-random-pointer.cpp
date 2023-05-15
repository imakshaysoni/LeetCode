/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
//       O(1) Spcae Complexity logic, TC O(N)
        // Node * dummy = new Node(-1);
        Node * temp = head;
        while(temp){
            Node * node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        temp = head;
        while(temp){
            if(temp->random==NULL) temp->next->random=NULL;
            else temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node * dummy = new Node(-1);
        Node * newHead = dummy;
        dummy->next = temp;
        while(temp){
            dummy->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            dummy = dummy->next;            
        }
        
        return newHead->next;
        
        
// //         Brute Force (Stored Nodes in Map & then put its references) O(N) Spcae Complexity logic, TC O(N)
//         unordered_map<Node*, Node*> m;
//         Node * temp = head;
//         Node * dummy = new Node(-1);
//         while(temp){
//             Node * n = new Node(temp->val);
//             m[temp] = n;
//             temp = temp->next;
//         }
        
//         temp = head;
//         while(temp){
//             m[temp]->next = m[temp->next];
//             m[temp]->random = m[temp->random];
//             temp = temp->next;
//         }
        
//         return m[head];
        
        
        
        
    
    }
};