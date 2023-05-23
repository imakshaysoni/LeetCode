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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> res;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* n = q.front();
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                res.push_back(n->val);
            }
            ans.push_back(res);
        }
        
        return ans;
        
        
    }
    
};