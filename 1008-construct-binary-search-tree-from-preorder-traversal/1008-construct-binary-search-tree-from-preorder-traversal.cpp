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
        
        int start = 0;
        int end = preorder.size()-1;
        return makeBST(preorder, start, end);
        
    }
    
    TreeNode* makeBST(vector<int> & preorder, int start, int end){
        
        if(start > end) return nullptr;
        
        
        int rootVal = preorder[start];
        TreeNode * root = new TreeNode(rootVal);
        
        int i = start+1;
        while(i<=end)
        {
            if(rootVal > preorder[i]) {
                i++;
            }
            else break;
        }
        
        root->left = makeBST(preorder, start+1, i-1);
        root->right = makeBST(preorder, i, end);
        
        return root;
        
        
    }
};