int maxPath;
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        maxPath = 0;
        
        height(root);
        
        return maxPath-1;
    }
    
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        maxPath = max(maxPath,lh+rh+1);
        
        return max(lh,rh)+1;
    }
};