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
        TreeNode* first=nullptr;
        TreeNode* mid=nullptr;
        TreeNode* last=nullptr;
        TreeNode* prev = nullptr;
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first&&last) swap(first->val, last->val);
        else swap(first->val, mid->val);
        
        
    }
    
    void inorder(TreeNode* root){
        
        if(!root) return;
        
        inorder(root->left);
        
        if(prev and prev->val > root->val)
        {
            if(first==nullptr){
                first=prev;
                mid = root;
            }
            else{
                last = root;
                return;
            }
        } 
        prev = root;
        inorder(root->right);
        
        
        
        
    }
};