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
    int maxi=INT_MIN;
    int maxPathSum(TreeNode* root) {
     
        if(root==NULL) return 0;      
        
        int maxPathSum = getMaxPathSum(root);
        return maxi;
    }
    
    int getMaxPathSum(TreeNode *root){
        
        if(root==NULL) return 0;        
        
        int leftMax = getMaxPathSum(root->left);
        int rightMax = getMaxPathSum(root->right);
        if(leftMax<0) leftMax=0;
        if(rightMax<0) rightMax=0;
        // if(root->val < 0) return max(leftMax, rightMax);
        maxi = max(maxi, leftMax+rightMax+root->val);        
        return root->val + max(leftMax, rightMax);
        
        
        
    }
};