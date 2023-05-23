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
    bool isBalanced(TreeNode* root) {
        int nodeCount = 1;
        int height = findHeightOfBT(root);
        if(height==-1) return false;
        return true;
    }
    
    
    int findHeightOfBT(TreeNode * root){
        if(root==NULL) return 0;
        int op1 = findHeightOfBT(root->left);
        int op2 = findHeightOfBT(root->right);
        if(op1==-1 || op2==-1) return -1;
        if(abs(op1-op2) > 1) return -1; 
        
        return 1 + max(op1,op2);
        
    }
};