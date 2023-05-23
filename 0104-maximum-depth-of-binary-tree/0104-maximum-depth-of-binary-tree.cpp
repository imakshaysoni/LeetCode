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
    int maxDepth(TreeNode* root) {
        
//         Recursive Approch, best as well TC: O(N), SC:O(N) worst Case
        // int count = BTHeight(root);
        // return count;
        
//         Method 2: Level order Traversing
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        int level=0;
        q.push(root);
        while(!q.empty()){
            level++;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode * temp = q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);    
            }
            
        }        
        // for(auto x: ans) cout<<x<<" ";
        return level;
    }
    
    
    int BTHeight(TreeNode* node){
        
        
        if(node==NULL) return 0;
        
        int op1 = 1 + BTHeight(node->left);
        int op2 = 1 + BTHeight(node->right);
        
        return max(op1,op2);
        
        
    }
};