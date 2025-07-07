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
            int size = q.size();
            ll minIdx =  q.front().second;
            ll maxIdx = 0;

            for(int i=0;i<size;i++){
                ll idx = q.front().second;
                TreeNode* node = q.front().first;
                q.pop();
                if(node->left) {
                    q.push({node->left,  (idx<<1)});
                } 
                if(node->right) q.push({node->right,  (idx<<1) + 1});
                if(i==size-1) maxIdx = idx;
                
            }
            maxWidth = max(maxWidth, (maxIdx-minIdx+1));
        }
        return maxWidth;
        

    }
};