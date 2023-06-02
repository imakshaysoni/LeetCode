/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=-1;
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt=0;
        inorder(root, k, cnt);
        return ans; 
        
        // Stack Based solution
        // stack<TreeNode*> st;
        // TreeNode * curr = root;
        // while(curr || !st.empty())
        // {            
        //     while(curr){
        //         st.push(curr);
        //         curr = curr->left;  
        //     }            
        //     curr = st.top();
        //     st.pop();
        //     k--;
        //     if(k==0) return curr->val;
        //     curr = curr->right;               
        // }
        // return -1;
        
    }
    
    void inorder(TreeNode* root, int k, int &count){
        
        if(!root) return;       
        inorder(root->left, k, count);
   
        // Process the current node
        count++;
        if (count == k) {
            ans = root->val; // Found the kth smallest element
            return;
        }
        
        inorder(root->right, k, count);
        
    }
};