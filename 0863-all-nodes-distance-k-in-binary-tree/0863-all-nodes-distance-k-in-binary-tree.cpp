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
        
        unordered_map<TreeNode*, TreeNode*> parent_track;
        unordered_set<TreeNode*> visited;
        mark_parent(root, parent_track);
        vector<int> req_nodes;
        queue<TreeNode*> q;
        int dist = 0;
        q.push(target);
        while(!q.empty()){
            int size = q.size();
            if(dist==k) break;
            for(int i=0;i<size;i++){
                TreeNode * node = q.front(); q.pop();
                if(isVisited(node, visited)) continue;
                visited.insert(node);
                if(node->left and !isVisited(node->left, visited)){
                    q.push(node->left);
                }
                if(node->right and !isVisited(node->right, visited)) q.push(node->right);
                if(parent_track[node]!=NULL and !isVisited(parent_track[node], visited)){
                    q.push(parent_track[node]);
                }                         
            }                     
                dist++;            
        }
        
        while(!q.empty()){
            req_nodes.push_back(q.front()->val);
            q.pop();
        }
        
        return req_nodes;            
        
    }
    
    bool isVisited(TreeNode * node, unordered_set<TreeNode*> visited){
        return visited.find(node)!=visited.end();
        
    }
    
    void mark_parent(TreeNode * root, unordered_map<TreeNode*, TreeNode*> &m){
        
        queue<TreeNode*> q;        
        q.push(root);
        m[root]=NULL;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    m[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    m[node->right]=node;
                }
            }          
            
            
        }
        
        
    }

};