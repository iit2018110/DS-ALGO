int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    
    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}


int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    
    
    if(!root->left) return  1+minDepth(root->right);
    if(!root->right) return 1+minDepth(root->left);
    
    return 1+min(minDepth(root->left),minDepth(root->right));
}