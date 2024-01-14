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
        
        return buildBTree(inorder, 0, inorder.size()-1,
                        postorder, postorder.size()-1, 0, inMap);        
        
        
    }
    
    TreeNode* buildBTree(vector<int>&inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, unordered_map<int,int>&inMap){
        
        if(postStart < postEnd || inStart>inEnd) return NULL;
        
        int rnode = postorder[postStart];
        int inRoot = inMap[rnode];
        int inLeft = inRoot - inStart;
        int inRight = inEnd - inRoot;
        
        TreeNode* root = new TreeNode(rnode);
        root->left = buildBTree(inorder, inStart, inRoot-1,
                               postorder, postStart-inRight-1, postEnd, inMap);
            
        root->right = buildBTree(inorder, inRoot+1, inEnd,
                                postorder, postStart-1, postStart-inRight, inMap);
        
        return root;
        
    }
};