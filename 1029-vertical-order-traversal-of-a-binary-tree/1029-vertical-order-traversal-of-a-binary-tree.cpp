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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> result;

        map<int, map<int, multiset<int>>> mapp;
        traverse(root, mapp, 0, 0);

        for(auto it: mapp){
            vector<int> ans;
            for(auto temp: it.second){
                for(auto val: temp.second) ans.push_back(val);
            }
            // sort(ans.begin(), ans.end());
            result.push_back(ans);
        }
        return result;
        
    }

    void traverse(TreeNode* root, map<int, map<int, multiset<int>>> & mapp, int x, int y){
        if(root==NULL) return;

        mapp[x][y].insert(root->val);

        traverse(root->left, mapp, x-1, y+1);
        traverse(root->right, mapp, x+1, y+1);
        return;
    }
};