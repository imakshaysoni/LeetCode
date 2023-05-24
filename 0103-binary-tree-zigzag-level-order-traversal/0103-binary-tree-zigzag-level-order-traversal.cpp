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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> zigZag;
        if(root==NULL) return zigZag;
        queue<TreeNode*> q;
        TreeNode * node = root;
        bool leftToRight = true;
        q.push(node);
        while(!q.empty()){
            int size = q.size();
            vector<int> res(size);
            for(int i=0;i<size;i++){
                int index = leftToRight ? i: size-i-1;
                TreeNode * temp = q.front();
                q.pop();
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                res[index] = temp->val;
            }
            leftToRight = !leftToRight;
            zigZag.push_back(res);            
            
        }
        
        
        return zigZag;
        
    }
};