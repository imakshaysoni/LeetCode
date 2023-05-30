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
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
        return nullptr;
    }
    
    unordered_map<int, int> inOrderIdx;
    int inOrderLen = inorder.size();
    for (int i = 0; i < inOrderLen; i++) {
        inOrderIdx[inorder[i]] = i;
    }
    int preOrderLen = preorder.size();
    TreeNode* root = buildUniqueBT(inorder, 0, inOrderLen - 1, preorder, 0, preOrderLen - 1, inOrderIdx);
    
    return root;
}

TreeNode* buildUniqueBT(vector<int>& in, int inStart, int inEnd, vector<int>& pre, int preStart, int preEnd, unordered_map<int, int>& iMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    if (preStart == preEnd) return new TreeNode(pre[preStart]);

    int rootVal = pre[preStart];
    int rootIdx = iMap[rootVal];

    int numsLeft = rootIdx - inStart;

    TreeNode* root = new TreeNode(rootVal);
    root->left = buildUniqueBT(in, inStart, rootIdx - 1, pre, preStart + 1, preStart + numsLeft, iMap);
    root->right = buildUniqueBT(in, rootIdx + 1, inEnd, pre, preStart + numsLeft + 1, preEnd, iMap);

    return root;
}

};