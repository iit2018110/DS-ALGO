#define vi vector<int>

void preTra(TreeNode* root, vi &res, int dep) {
    if(root == NULL) return;
    
    if(dep==res.size()) res.push_back(root->val);
    preTra(root->right,res,dep+1);
    preTra(root->left,res,dep+1);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vi res;
        preTra(root,res,0);
        
        return res;
    }
};