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
//     bard Optimized
    vector<int> rightSideView(TreeNode* root) {
  vector<int> result;
  if (root == NULL) {
    return result;
  }

  // Level order traversal using a deque
  std::deque<TreeNode*> q;
  q.push_back(root);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode* temp = q.front();
      q.pop_front();
      if (i == 0) {
        result.push_back(temp->val);
      }
      if (temp->right != NULL) {
        q.push_back(temp->right);
      }
      if (temp->left != NULL) {
        q.push_back(temp->left);
      }
    }
  }

  return result;
}
    
    
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> result;
//         if(root==NULL) return result;
// //         Recurssive Solution TC:O(N), SC(H) Height Of Tree, max N when we get squeed tree
        
// //         rightView
//         rightView(root, result, 0);
//         return result;
        
// //         LeftView
//         leftView(root, result, 0);
//         return result;
        
        
//         // Level Order Traversing TC O(N) SC O(N)
//         queue<TreeNode*> q;        
//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0;i<size;i++){                
//                 TreeNode * temp = q.front();
//                 q.pop();
//                 if(temp->right) q.push(temp->right);
//                 if(temp->left) q.push(temp->left);
//                 if(i==0)
//                     result.push_back(temp->val);
//             }
//         }
        
//         return result;
        
//     }
    
//     void rightView(TreeNode* root, vector<int> &res, int level){
//         if(root==NULL) return;
        
//         if(res.size()==level) res.push_back(root->val);
//         // rightView =right then Left
//         rightView(root->right, res, level+1);
//         rightView(root->left, res, level+1);
//     }
    
//     void leftView(TreeNode* root, vector<int> &res, int level){
//         if(root==NULL) return;
        
//         if(res.size()==level) res.push_back(root->val);
//         // leftView =Left then Right
//         leftView(root->left, res, level+1);
//         leftView(root->right, res, level+1);
//     }
};