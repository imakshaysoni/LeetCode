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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = 1 + findLeftHeight(root->left);
        int rightHeight = 1 + findRightHeight(root->right);
        
        if(leftHeight==rightHeight) return (1<<leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
    
    int findLeftHeight(TreeNode* root){        
        if(!root) return 0;
        int h = 1 + findLeftHeight(root->left);
        return h;               
    }
    
    int findRightHeight(TreeNode * root){
        if(!root) return 0;
        int h = 1 + findRightHeight(root->right);
        return h;               
    }
};