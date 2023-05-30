return root;
}
TreeNode * buildUniqueBT(vector<int> &in, int inStart, int inEnd, vector<int> &pre, int preStart, int preEnd, unordered_map<int, int> &iMap)
{
int rootVal = pre[preStart];
if(preStart>preEnd || inStart>inEnd) return nullptr;
TreeNode * root = new TreeNode(rootVal);
int rootIdx = iMap[root->val];
int numsLeft = rootIdx-inStart;
root->left = buildUniqueBT(in,inStart, rootIdx-1, pre, preStart+1, preStart+numsLeft , iMap);
root->right = buildUniqueBT(in, rootIdx+1, inEnd, pre, preStart+numsLeft+1, preEnd, iMap);
return root;
}
};