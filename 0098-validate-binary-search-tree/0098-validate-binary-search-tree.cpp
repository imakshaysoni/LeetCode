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
    bool isValidBST(TreeNode* root) {
        
        
        long mini = LONG_MIN;
        long maxi = LONG_MAX;
        
        return validBST(root, mini, maxi);
        
        
       // int result = isValid(root);
       //  if(result==0) return false;
       //  return true;
    }
    
    bool validBST(TreeNode* root, long mini, long maxi){
        
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) return false;
        return validBST(root->left, mini, root->val) and validBST(root->right, root->val, maxi);        
    }
    
    int isValid(TreeNode* root){
        
        if(!root || isLeaf(root)) return 1;
        
        if(root->left and root->left->val >= root->val) return 0;
        if(root->right and root->right->val <= root->val) return 0;
        
        long maxi = LONG_MIN;
        long mini = LONG_MAX;
        if(root->left)
            maxi = getMaxVal(root->left);
        if(root->right)
            mini = getMinVal(root->right);
        
        if(maxi >= root->val) return 0;
        if(mini <= root->val) return 0;
        
        return isValid(root->left) and isValid(root->right);        
        return 1;        
        
        
    }
    int getMaxVal(TreeNode * root){
        while(root->right) root=root->right;
        return root->val;
    }
    
    int getMinVal(TreeNode * root){
        while(root->left) root=root->left;
        return root->val;
    }
    int isLeaf(TreeNode* root){
        if(root->left ==NULL and root->right==NULL) return 1;
        return 0;
    }
};