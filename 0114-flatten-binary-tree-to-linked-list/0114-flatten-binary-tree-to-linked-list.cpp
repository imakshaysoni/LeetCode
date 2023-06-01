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
        
        flatBT(root);
        
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