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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        path(root, s, ans);
        return ans;
    }

    void path(TreeNode* root, string p, vector<string> &ans){
        if(root==NULL) return;
        if(root->left==root->right){
            p = p+to_string(root->val);
            ans.push_back(p);
            return;
        }

        p = p+to_string(root->val) + "->";
        path(root->left, p, ans);
        path(root->right, p, ans);
        return;

    }

    

};