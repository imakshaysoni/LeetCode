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
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        
        if(!root) return;
//         Recurssive
        // flatBT(root);
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode * curr = st.top(); st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            
            curr->left = nullptr;
            if(!st.empty())
                curr->right = st.top();
            // else curr->right = nullptr;
            
        }
        
        
        // return root;
    }
    

//     TC O(N), SC O(1)
    void flatBT(TreeNode * root){
        
        if(!root) return;
        
        flatBT(root->right);
        flatBT(root->left);
        
        root->left = nullptr;
        root->right = prev;
        prev = root;      
        
    }
};