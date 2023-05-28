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
    bool checkTree(TreeNode* root) {
        // Add your code here
        
        int result = childSum(root);
        // cout<<result<<endl;
        if(result==INT_MAX) return 0;
        return 1;
    }
    
    int childSum(TreeNode * root){
        if(!root) return 0;
        
        int leftSum = childSum(root->left);
        int rightSum = childSum(root->right);
        
        if(isLeafNode(root)) return root->val;
        
        if(leftSum==INT_MAX or rightSum ==INT_MAX) return INT_MAX;
        if(leftSum+rightSum != root->val) return INT_MAX;
        
        return root->val + leftSum + rightSum;
    }
    
    bool isLeafNode(TreeNode * root){
        cout<<"checking leaf";
        if(root->left==NULL and root->right==NULL) return true;
        return false;
    }
};