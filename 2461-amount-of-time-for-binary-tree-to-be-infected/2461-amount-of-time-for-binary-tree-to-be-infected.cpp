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
    int result = INT_MIN;
    int amountOfTime(TreeNode* root, int start) {
        
        if(root==NULL) return 0;
        int res = solve(root, start);
        return result;

        

    }

    int solve(TreeNode* root, int start){
        if(root==NULL) return 0;
        int lh = solve(root->left, start);
        int rh = solve(root->right, start);

        if(root->val==start){
            result = max({lh, rh});
            return -1;
        }
        if(lh>=0 and rh>=0){
            return max(lh, rh) + 1;
        }
        else{
            int dist = abs(lh) + abs(rh);
            result = max(result, dist);
            return min(lh, rh) -1;
        }
        return 0;
    }
};