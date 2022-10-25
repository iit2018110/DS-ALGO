long prevVal;

bool isValid(TreeNode* root) {
    if(root==NULL) return true;
    
    if(!isValid(root->left)) return false;;
    
    if(root->val <= prevVal) return false;
    else prevVal = root->val;
    
    if(!isValid(root->right)) return false;
    
    return true;
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prevVal = LONG_MIN;
        
        if(isValid(root)) return true;
        else return false;
    }
};