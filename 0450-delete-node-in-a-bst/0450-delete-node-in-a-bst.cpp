class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            } else if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            } else {
                // Node with two children: Get inorder successor (smallest in the right subtree)
                TreeNode* prev = root->left;
                TreeNode* succ = root->left;
                while (succ->right) succ = succ->right;
                succ->right = root->right;
                delete root;
                return prev;
            }
        }
        return root;
    }
};