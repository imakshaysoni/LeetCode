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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int max_val = INT_MAX;
        int start = 0;
        return buildTree(preorder, start, max_val);
    }

    TreeNode* buildTree(vector<int> & preorder, int &start, int &max_val){

        if(start >= preorder.size() || preorder[start]>=max_val) return nullptr;

        TreeNode* root = new TreeNode(preorder[start]);
        start++;
        root->left = buildTree(preorder, start, root->val);
        root->right = buildTree(preorder,start, max_val);
        return root;

    }
};