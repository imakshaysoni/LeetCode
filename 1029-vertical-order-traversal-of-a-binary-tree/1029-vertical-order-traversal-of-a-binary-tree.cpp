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
        if(root==NULL) return {{}};
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, vector<pair<int,int>>> mapper;
        q.push({root, {0,0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int h_level = q.front().second.first;
            int v_level = q.front().second.second;
            mapper[v_level].push_back({h_level,node->val});
            q.pop();
            if(node->left) q.push({node->left, {h_level+1, v_level-1}});
            if(node->right) q.push({node->right, {h_level+1, v_level+1}});
            
        }
        vector<vector<int>> result;
        for(auto nodes: mapper){
            vector<int> temp;
            sort(nodes.second.begin(), nodes.second.end());
            for(auto node: nodes.second){
                temp.push_back(node.second);
            }
            result.push_back(temp);
        }
        
        return result;
        
        
    }
};