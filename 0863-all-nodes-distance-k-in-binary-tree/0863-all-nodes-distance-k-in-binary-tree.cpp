// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
//         unordered_map<TreeNode*, TreeNode*> parent_track;
//         unordered_set<TreeNode*> visited;
//         mark_parent(root, parent_track);
//         vector<int> req_nodes;
//         queue<TreeNode*> q;
//         int dist = 0;
//         q.push(target);
//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode * node = q.front(); q.pop();
//                 if(visited.find(node)!=visited.end()) continue;
//                 visited.insert(node);
//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right) q.push(node->right);
//                 if(parent_track[node]!=NULL){
//                     q.push(parent_track[node]);
//                 }      
//                 if(dist==k) req_nodes.push_back(node->val);
//             }                     
//                 if(dist==k) break;
//                 dist++;           
//         }
        
//         return req_nodes;            
        
//     }
    
//     void mark_parent(TreeNode * root, unordered_map<TreeNode*, TreeNode*> &m){
        
//         queue<TreeNode*> q;        
//         q.push(root);
//         m[root]=NULL;
//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode * node = q.front();
//                 q.pop();
//                 if(node->left){
//                     q.push(node->left);
//                     m[node->left]=node;
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                     m[node->right]=node;
//                 }
//             }          
            
            
//         }
        
        
//     }

// };

// MY code but code quality improve by ChatGPT
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        unordered_set<TreeNode*> visited;
        markParent(root, parentTrack);
        vector<int> result;
        queue<TreeNode*> q;
        int distance = 0;
        q.push(target);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (visited.count(node)) continue;
                visited.insert(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (parentTrack[node]) q.push(parentTrack[node]);
                if (distance == k) result.push_back(node->val);
            }
            if (distance == k) break;
            distance++;
        }
        return result;
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
