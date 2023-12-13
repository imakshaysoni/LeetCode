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
        queue<TreeNode*> q;
        vector<vector<int>> zigzag;
        if(root==NULL) return zigzag;
        q.push(root);
        bool fromLeft=true;
        while(!q.empty()){
            int size = q.size();
            vector<int> nodes(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int idx=i;
                if(fromLeft!=true) idx = size-i-1;
                nodes[idx] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);                    
            }
            fromLeft = !fromLeft;
            zigzag.push_back(nodes);
        }
        
        return zigzag;
    }
};