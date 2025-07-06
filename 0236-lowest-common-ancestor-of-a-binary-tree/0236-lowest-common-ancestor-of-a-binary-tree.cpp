/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans = nullptr;
        bool op = lca(root, p, q, ans);
        return ans;

        
    }
    bool lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root==NULL) return false;
        // if(root==p or root==q) {
        //     return true;
        // }
        bool op1 = lca(root->left, p, q, ans);
        bool op2 = lca(root->right, p, q, ans);
        bool op3 = (root==p or root==q);
        if(op1+op2+op3 >=2) ans = root;
        return op1 or op2 or op3;
    }
};