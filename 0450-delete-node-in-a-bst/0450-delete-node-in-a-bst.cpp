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
//     This is My Solution, Explanation is added by ChatGPT
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Check if the tree is empty
        if (!root) {
            return nullptr;
        }
        
        // Check if the current node is the target node to delete
        if (root->val == key) {
            return helper(root); // Call the helper function for deleting the node
        }
        
        TreeNode* curr = root;
        while (curr) {
            // Check if the key is less than the current node's value
            if (curr->val > key) {
                // Check if the left child is the target node to delete
                if (curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left); // Call the helper function for deleting the node
                    break;
                } else {
                    curr = curr->left; // Traverse to the left child
                }
            }
            // Check if the key is greater than the current node's value
            else {
                // Check if the right child is the target node to delete
                if (curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right); // Call the helper function for deleting the node
                    break;
                } else {
                    curr = curr->right; // Traverse to the right child
                }
            }           
        }        
        return root; // Return the modified root node
    }
    
    TreeNode* helper(TreeNode* root) {
        // Check if the left child is NULL
        if (!root->left) {
            return root->right; // Replace the node with its right child
        }
        // Check if the right child is NULL
        if (!root->right) {
            return root->left; // Replace the node with its left child
        }
        
        TreeNode* rightMost = findRightMostNode(root->left); // Find the rightmost node in the left subtree
        rightMost->right = root->right; // Link the right subtree of the deleted node to the rightmost node in the left subtree
        return root->left; // Replace the node with its left child
    }
    
    TreeNode* findRightMostNode(TreeNode* root) {
        while (root->right) {
            root = root->right; // Traverse to the rightmost node
        }
        return root; // Return the rightmost node
    }
};
