int idx;

TreeNode * createTree(vector<int>& pre, int ll, int rl) {
    if(idx >= pre.size() or pre[idx] < ll or pre[idx] > rl) return NULL;
    
    TreeNode * node = new TreeNode(pre[idx++]);
    node->left = createTree(pre,ll,node->val);
    node->right = createTree(pre,node->val,rl);
    
    return node;
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int ll = -1, rl = (int)1e8 + 1;
        idx = 0;
        
        return createTree(pre,ll,rl);
    }
};