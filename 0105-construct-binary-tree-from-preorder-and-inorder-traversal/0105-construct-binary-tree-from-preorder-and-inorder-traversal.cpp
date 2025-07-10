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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int start = 0;
        int end = inorder.size();
        int idx = 0;
        return solve(preorder, inorder, idx, start, end-1);
        
    }

    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &idx, int start, int end){

        if(start > end or idx>=preorder.size()) return nullptr;

        int rootVal = preorder[idx];
        idx++;
        int i=start;
        while(i<=end){
            if(inorder[i]==rootVal) break;
            i++;
        } 
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, idx, start, i-1);
        root->right = solve(preorder, inorder, idx, i+1, end);

        return root;
    }
};