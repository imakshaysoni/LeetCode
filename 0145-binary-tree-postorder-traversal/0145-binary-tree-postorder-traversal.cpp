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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        while(root!=NULL){
            postorder.push_back(root->val);
            if(root->right){
                TreeNode* curr = root->right;
                while(curr->left) curr = curr->left;
                curr->left = root->left;
                TreeNode* temp = root;
                root = root->right;
                temp->right = NULL;
            }
            else{
                root = root->left;
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
        
    }
};