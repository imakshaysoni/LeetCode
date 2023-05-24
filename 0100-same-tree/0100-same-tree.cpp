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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return isIdentical(p,q);
        
    }
    
    bool isIdentical(TreeNode* p, TreeNode* q){
        
        if(p==q) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) return false;
        
        bool op1 = isIdentical(p->left, q->left);
        if(op1==false) return false;
        bool op2= isIdentical(p->right, q->right);
        if(op2==false) return false;
        return true;
        
        
    }
};