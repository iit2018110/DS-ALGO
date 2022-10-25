int maxs;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        maxs = INT_MIN;
        maxSum(root);
        
        return maxs;
    }
    
    int maxSum(TreeNode* root) {
        if(root==NULL) return 0;
        
        int ls = max(0,maxSum(root->left));
        int rs = max(0,maxSum(root->right));
        
        maxs = max(maxs,ls+rs+root->val);
        
        return root->val + max(ls,rs);
    }
};