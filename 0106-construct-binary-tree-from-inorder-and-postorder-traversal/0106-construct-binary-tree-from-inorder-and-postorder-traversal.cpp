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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     
        unordered_map<int, int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        
        TreeNode* root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int> &in, int inStart, int inEnd, vector<int> &post, int postStart, int postEnd, unordered_map<int, int> &inMap)
    {
        
        if(inStart > inEnd || postStart > postEnd) return nullptr;
        
        int inRoot = post[postEnd];
        int rootIdx = inMap[inRoot];
        int numsLeft = rootIdx-inStart;
        TreeNode* root = new TreeNode(inRoot);
        
        root->left = buildTree(in, inStart, rootIdx-1, post, postStart, postStart+numsLeft-1,inMap);
        // root->right = buildTree(in, rootIdx+1, inEnd, post, postStart+numsLeft+1, postEnd-1, inMap);
        root->right = buildTree(in, rootIdx+1, inEnd, post, postStart+numsLeft, postEnd-1, inMap);
        
        return root;        
        
    }
};