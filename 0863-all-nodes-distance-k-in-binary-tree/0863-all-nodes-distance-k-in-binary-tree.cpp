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
    int dist=0;
    q.push(target);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (visited.find(node) != visited.end()) continue;
            visited.insert(node);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if (parent_track[node]) q.push(parent_track[node]);
            if (dist == k) req_nodes.push_back(node->val);  // Store the nodes at distance k
        }
        dist++;  // Increment distance inside the inner for loop
        if (dist > k) break;  // Stop when the required distance is reached
    }
    return req_nodes;
}

void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m) {
    queue<TreeNode*> q;
    q.push(root);
    m[root] = NULL;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                m[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                m[node->right] = node;
            }
        }
    }
}

};