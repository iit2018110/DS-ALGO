class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        
        if(root == p or root == q) return root;
        TreeNode* lt = lowestCommonAncestor(root->left,p,q);
        TreeNode* rt = lowestCommonAncestor(root->right,p,q);
        
        if(lt and rt) return root;
        if(!lt and !rt) return NULL;
        
        return lt? lt : rt;
    }
};