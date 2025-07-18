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
 class BstIterator{
        stack<TreeNode*> st;
        bool rev;
        public:
        BstIterator(TreeNode* root, bool reverse){
            rev = reverse;
            pushAll(root);
        }

        void pushAll(TreeNode* root){
            while(root){
                st.push(root);
                if(rev==true) root = root->right;
                else root = root->left;
            }
        }

        int next(){
            TreeNode* root = st.top();
            st.pop();

            if(rev==true){
                pushAll(root->left);
            }
            else{
                pushAll(root->right);
            }

            return root->val;
            
        }
 };
class Solution {
public:

    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;

        BstIterator nextOne(root, false);
        BstIterator prevOne(root, true);
        
        int left = nextOne.next();
        int right = prevOne.next();

        while(left<right){
            if(left+right==k) return true;
            if(left+right < k) left = nextOne.next();
            else right = prevOne.next();
        } 

        return false;



        // return solve(root, k, st);


        
    }

    bool solve(TreeNode* root, int k, set<int> &st){

            if(root==NULL) return false;
            bool op1 = solve(root->left, k, st);
            
            int rem = k - root->val;
            
            if(st.find(rem)!=st.end()) return true;

            st.insert(root->val);
            bool op2 = solve(root->right, k, st);
            return op1 or op2;
    }


};