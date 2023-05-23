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
    int maxDepth(TreeNode* root) {
        
        int count = BTHeight(root);
        return count;
    }
    
    int BTHeight(TreeNode* node){
        
        
        if(node==NULL) return 0;
        
        int op1 = 1 + BTHeight(node->left);
        int op2 = 1 + BTHeight(node->right);
        
        return max(op1,op2);
        
        
    }
};