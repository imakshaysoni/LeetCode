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
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    TreeNode* next() {

        TreeNode* node = st.top();
        st.pop();

        if(node->right){
            pushAll(node->right);
        }

        return node;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* root){
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        BSTIterator *bst = new BSTIterator(root);
        TreeNode* prev = nullptr;
        TreeNode* first=nullptr;
        TreeNode* second= nullptr;
        while(bst->hasNext()){
            TreeNode* node = bst->next();
            if(prev!=nullptr and node->val < prev->val){
                if(first==nullptr) first = prev;
                second = node;
            }
            prev = node;
        }
        if(first and second) swap(first->val, second->val);
        return;
    }
};