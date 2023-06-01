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
    vector<int> inorderTraversal(TreeNode* root) {
        
//         Moris Traversal : TC O(N), SC O(1)
        vector<int> ans;        
        morisTraversal(root, ans);
        // string mode = "inorder";
        // traverse(root, ans, mode);
        return ans;
        
    }
    
    void traverse(TreeNode* root, vector<int> &ans, string &mode){
        
        if(root==NULL) return;
        
        if(mode=="preorder")
        {
            ans.push_back(root->val);
            traverse(root->left, ans, mode);
            traverse(root->right, ans, mode);
        }
        else if(mode=="postorder"){
            traverse(root->left, ans, mode);
            traverse(root->right, ans, mode);
            ans.push_back(root->val);
        }
        else if(mode=="inorder"){
            traverse(root->left, ans, mode);
            ans.push_back(root->val);
            traverse(root->right, ans, mode);
        }
        
    }
    
    void morisTraversal(TreeNode* root, vector<int> &inorder){
        
        TreeNode * curr = root;
        while(curr)
        {
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
            TreeNode * node = curr->left;
            while(node->right and node->right !=curr)
            {
                node=node->right;
            }
            
            if(node->right==NULL){
                node->right=curr;
                curr = curr->left;
            }
            else{
                node->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }       
        }
    }
};