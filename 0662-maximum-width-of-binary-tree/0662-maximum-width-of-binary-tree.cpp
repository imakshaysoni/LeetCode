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
    int widthOfBinaryTree(TreeNode* root) {
        
        typedef unsigned long long ll;
        queue<pair<TreeNode*, ll>> q;
        ll maxWidth = 0;
        q.push({root, 0});
        while(!q.empty()){

            ll L = q.front().second;
            ll R = q.back().second;
            maxWidth = max(maxWidth, R-L+1);

            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                ll idx = q.front().second;
                q.pop();
                if(node->left) q.push({node->left, 2*idx});
                if(node->right) q.push({node->right, 2*idx + 1});
            }
        


        }
        return maxWidth;
    }
};