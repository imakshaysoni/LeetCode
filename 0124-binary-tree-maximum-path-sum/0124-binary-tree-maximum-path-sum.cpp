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
        int maxPath = getMaxSumPath(root);
        return maxi;
    }
    
    int getMaxSumPath(TreeNode* root){
        
        if(root==NULL) return 0;
        
        int leftSum = getMaxSumPath(root->left);
        int rightSum = getMaxSumPath(root->right);
        if(leftSum<0) leftSum=0;
        if(rightSum<0) rightSum=0;
        
        maxi = max(maxi, leftSum+rightSum+root->val);
        return root->val + max(leftSum, rightSum);
        
        
    }
};