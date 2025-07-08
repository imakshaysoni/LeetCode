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
    void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mapper){

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                  q.push(node->left);
                  mapper[node->left] = node;  
                }
                if(node->right) {
                    q.push(node->right);
                    mapper[node->right] = node; 
            }
        }

    }

        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(target==root){
            if(k==0) return {root->val};
        }
        unordered_map<TreeNode*, TreeNode*> mapper;
        getParent(root, mapper);

        vector<int> ans;
        traverse(target, ans, k);
        set<TreeNode*> st;
        st.insert(target);
        queue<pair<TreeNode*, int>> q;
        if(mapper.find(target)!=mapper.end()){
            q.push({mapper[target], 1});
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();
                if(level==k) {
                    ans.push_back(node->val);
                }
                if(level>k) break;
                if(node->left and st.find(node->left)==st.end()){
                    q.push({node->left, level+1});
                }
                if(node->right and st.find(node->right)==st.end()){
                    q.push({node->right, level+1});
                }
                if(mapper.find(node)!=mapper.end() and st.find(mapper[node])==st.end()){
                    q.push({mapper[node], level+1});
                }
                st.insert(node);
            }
        }
        return ans;
        
    }
    void traverse(TreeNode* target, vector<int> &ans, int k){

        queue<pair<TreeNode* , int>> q;
        q.push({target, 0 });
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node  = q.front().first;
                int level = q.front().second;
                q.pop();
                if(level==k) ans.push_back(node->val);
                if(level>k) break;
                if(node->left) q.push({node->left, level+1});
                if(node->right) q.push({node->right, level+1});
            }
        }
    }
};