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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root->left, root->right);
    }
    
    bool check(TreeNode* lnode, TreeNode* rnode){
        if(lnode==rnode) return true;
        else if(lnode==NULL or rnode==NULL) return false;
        
        if(lnode->val!=rnode->val) return false;
        return check(lnode->left, rnode->right) and check(lnode->right, rnode->left);
    }
};