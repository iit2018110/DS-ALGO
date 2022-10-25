TreeNode * buildTree_(vector<int>& post, int psi, int pei, vector<int>& in, int isi, int iei) {
    if(isi > iei) return NULL;
    
    int idx = isi;
    while(in[idx] != post[pei])
        idx++;
    
    int lols = idx - isi;
    
    TreeNode * node = new TreeNode(post[pei]);
    node->left = buildTree_(post,psi,psi+lols-1,in,isi,idx-1);
    node->right = buildTree_(post,psi+lols,pei-1,in,idx+1,iei);
    
    return node;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int sz = in.size();
        
        return buildTree_(post,0,sz-1,in,0,sz-1);
    }
};