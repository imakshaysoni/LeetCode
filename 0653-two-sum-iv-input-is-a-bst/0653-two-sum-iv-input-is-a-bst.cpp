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
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool forword;
    BSTIterator(TreeNode* root, bool forr) {
        forword = forr;
        pushAll(root);
    }
    
    int next() {
        TreeNode * node = st.top();
        st.pop();
        if(forword){
          pushAll(node->right);   
        }
        else pushAll(node->left);
        return node->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(forword) root=root->left;
            else root=root->right;
        }
    }
};
class Solution {
private:
    
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        
        int i = l.next();
        int j = r.next();
        while(true){
            if(i>=j) return false;            
            int sum = i+j;            
            if(sum== k) return true;
            else if(sum > k) {j=r.next();}
            else {i=l.next();}
        }
        
        return false;
    
        
        
        
    }
};