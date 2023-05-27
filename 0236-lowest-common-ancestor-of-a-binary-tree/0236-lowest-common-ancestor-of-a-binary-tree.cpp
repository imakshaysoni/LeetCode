/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
        
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        path(root, p, path1);
        path(root, q, path2);
        
        int len1 = path1.size();
        int len2 = path2.size();
        
        for(int i=1;i<min(len1, len2);i++){
            if(path1[i]!=path2[i])
                return path1[i-1];
        }
        return path1[min(len1,len2)-1];
        
        return root;
    }
    
    bool path(TreeNode* root, TreeNode* p, vector<TreeNode*> &res){
        
        if(root==NULL) return false;        
        
        res.push_back(root);
        
        if(root==p){
            return true;
        }
        
        bool op1 = path(root->left, p, res);
        bool op2 = false;
        if(op1==false)
            op2 = path(root->right, p, res);
        if(op1==false and op2==false)
        {
            res.pop_back();     
            return false;
        }
            
        return true;
    }
};