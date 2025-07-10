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
TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &idx, int start, int end){

        if(start > end or idx<0) return nullptr;

        int rootVal = preorder[idx];
        idx--;
        int i=start;
        while(i<=end){
            if(inorder[i]==rootVal) break;
            i++;
        } 
        TreeNode* root = new TreeNode(rootVal);
        root->right = solve(preorder, inorder, idx, i+1, end);
        root->left = solve(preorder, inorder, idx, start, i-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start = 0;
        int end = inorder.size();
        int idx = postorder.size()-1;
        // reverse(postorder.begin(), postorder.end());
        return solve(postorder, inorder, idx, start, end-1);

    }
};