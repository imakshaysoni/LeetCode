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
        
        map<int, map<int, vector<int>>> m;
        vector<vector<int>> result;
        if(root==NULL) return result;
        traverseAndFill(root, m, 0, 0);
        
        for(auto a: m){
            vector<int> cols;
            for(auto b: a.second){
                sort(b.second.begin(),b.second.end());
                for(auto x: b.second) cols.push_back(x);
            }
            result.push_back(cols);
        }      
        return result;
        
    }
    
    void traverseAndFill(TreeNode * root, map<int, map<int, vector<int>>> &m, int row, int col)
    {
        
        if(root==NULL) return;
        
        m[col][row].push_back(root->val);
        
        traverseAndFill(root->left, m, row+1, col-1);
        traverseAndFill(root->right, m, row+1, col+1);   
        
    }
};