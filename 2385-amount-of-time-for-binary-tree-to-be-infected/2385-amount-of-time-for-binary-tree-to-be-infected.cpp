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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        unordered_set<TreeNode*> visited;
        markParent(root, parentTrack);
        
        TreeNode* targetNode = getTargetNode(root, start);
        
        int minTimeToBurn = burnTree(targetNode, parentTrack, visited);
        
        return minTimeToBurn-1;
    }
    
    int burnTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentTrack, unordered_set<TreeNode*> &visited){
        
        if(!root) return 0;
        if(visited.count(root)) return 0;
        visited.insert(root);
        int left = 1 + burnTree(root->left, parentTrack, visited);
        int right = 1 + burnTree(root->right, parentTrack, visited);
        int parent = 1 + burnTree(parentTrack[root], parentTrack, visited);
        
        return max(left, max(right, parent));
        
    }
    
    TreeNode* getTargetNode(TreeNode* root, int target){
        
        if(!root) return nullptr;
        
        if(root->val==target) return root;
        
        TreeNode* left = getTargetNode(root->left, target);
        TreeNode* right = getTargetNode(root->right, target);
        
        if(left==NULL and right==NULL) return nullptr;
        if(left) return left;
        return right;
        
    }
    
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack) {
        queue<TreeNode*> q;
        q.push(root);
        parentTrack[root] = nullptr;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    parentTrack[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    parentTrack[node->right] = node;
                }
            }
        }
    }
};