class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        
        return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode *p, TreeNode *q) {
        if(p==NULL or q==NULL) return p==q;
        
        return p->val==q->val and isMirror(p->left,q->right) and isMirror(p->right,q->left);
    }
};