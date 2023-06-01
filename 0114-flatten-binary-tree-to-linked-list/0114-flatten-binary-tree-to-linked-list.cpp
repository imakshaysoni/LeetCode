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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        TreeNode* prev = nullptr;
        
        // Approach 1: Recursive Approach
        // Time Complexity: O(N), where N is the number of nodes in the binary tree
        // Space Complexity: O(N) due to the recursive call stack
        
        flatBT(root, prev);
        
        // Approach 2: Stack Approach
        // Time Complexity: O(N), where N is the number of nodes in the binary tree
        // Space Complexity: O(N) due to the stack usage
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
            curr->left = nullptr;
            if (!st.empty())
                curr->right = st.top();
            else
                curr->right = nullptr;
        }
        
        // Approach 3: Morris Traversal
        // Time Complexity: O(N), where N is the number of nodes in the binary tree
        // Space Complexity: O(1) as no additional space is used
        TreeNode* node = root;
        while (node) {
            if (node->left) {
                TreeNode* prev = node->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = node->right;
                node->right = node->left;
                node->left = nullptr;
                node = node->right;
            } else {
                node = node->right; 
            }          
        }   
    }
    
    // Recursive function to flatten the binary tree
    void flatBT(TreeNode* root, TreeNode*& prev) {
        if (!root) return;
        
        flatBT(root->right, prev);
        flatBT(root->left, prev);
        
        root->left = nullptr;
        root->right = prev;
        prev = root;      
    }
};
