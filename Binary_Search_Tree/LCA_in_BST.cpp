class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        if(root == p or root == q) return root;
        
        if(root->val > min(p->val,q->val) and root->val < max(p->val,q->val)) return root;
        
        if(root->val > max(p->val,q->val)) return lowestCommonAncestor(root->left,p,q);
        if(root->val < min(p->val,q->val)) return lowestCommonAncestor(root->right,p,q);
        
        return NULL;
    }
};