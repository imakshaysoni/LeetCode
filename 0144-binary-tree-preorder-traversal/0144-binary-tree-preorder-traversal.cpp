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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;        
        string mode = "preorder";
        traverse(root, ans, mode);
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
};