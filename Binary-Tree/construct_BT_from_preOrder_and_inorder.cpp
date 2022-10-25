TreeNode * buildTree_(vector<int>& pre, int psi, int pei, vector<int>& in, int isi, int iei) {
    if(isi > iei) return NULL;
    
    int idx = isi;
    while(in[idx] != pre[psi])
        idx++;
    
    int lols = idx - isi;
    
    TreeNode * node = new TreeNode(pre[psi]);
    
    node->left = buildTree_(pre,psi+1,psi+lols,in,isi,idx-1);
    node->right = buildTree_(pre,psi+lols+1,pei,in,idx+1,iei);
    
    return node;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int sz = pre.size();
        
        return buildTree_(pre,0,sz-1,in,0,sz-1);
    }
};