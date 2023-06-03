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
        
        if(!root) return nullptr;
        
        TreeNode* curr = root;
        
         while (curr) {
        int val = curr->val;

        if (val < p->val && val < q->val) {
            curr = curr->right;
        } else if (val > p->val && val > q->val) {
            curr = curr->left;
        } else {
            break;
        }
    }
        return curr;
        
//         if(!root) return nullptr;
        
//         int curr = root->val;
        
//         if(curr < p->val and curr < q->val) return lowestCommonAncestor(root->right, p, q);
//         if(curr > p->val and curr > q->val) return lowestCommonAncestor(root->left, p, q);
//         return root;                
    }
    
        
};