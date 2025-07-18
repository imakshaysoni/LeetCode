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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int preStart = 0;
        int preEnd = preorder.size()-1;
        int postStart = 0;
        return buildTree(preorder, postorder, preStart, preEnd, postStart);
        
    }

    TreeNode* buildTree(vector<int>&preorder, vector<int>&postorder, int preStart, int preEnd, int postStart){

        if(preStart>preEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd) return root;
        
        int nextNode = preorder[preStart+1];
        int j = postStart;
        while(postorder[j]!=nextNode){
            j++;
        }

        int nodes = j-postStart+1;
        root->left = buildTree(preorder, postorder, preStart+1, preStart+nodes, postStart);
        root->right = buildTree(preorder, postorder, preStart+nodes+1, preEnd, j+1);

        return root;

    }
};