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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return nullptr;
        
        if(root->val==key) return helper(root);
        
        TreeNode* curr = root;
        while(curr){
            if(curr->val > key){
                if(curr->left and curr->left->val==key){
                    curr->left = helper(curr->left);
                    break;
                }
                else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->right and curr->right->val==key){
                    curr->right = helper(curr->right);
                    break;
                }
                else curr = curr->right;
            }           
        }        
        return root;
        
    }
    
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        
        TreeNode * rightMost = findRightMostNode(root->left);
        rightMost->right = root->right;
        return root->left;
    }
    TreeNode* findRightMostNode(TreeNode * root){
        while(root->right) root=root->right;
        return root;
    }
};