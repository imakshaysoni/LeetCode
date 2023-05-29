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