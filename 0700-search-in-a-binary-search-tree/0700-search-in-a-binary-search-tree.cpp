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
    TreeNode* searchBST(TreeNode* root, int val) {
     
        
        TreeNode * node = getNode(root, val);
        return node;
    }
    
    TreeNode* getNode(TreeNode* root, int val){
        
        if(!root) return nullptr;
        
        if(val==root->val) return root;
        
        if(val > root->val) {
            return getNode(root->right, val);
        }
        else{
            return getNode(root->left, val);
        }
        
    }
};