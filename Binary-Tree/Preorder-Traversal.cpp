#define vi vector<int>

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vi res;
        if(root==NULL) return res;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()) {
            TreeNode * node = stk.top();
            stk.pop();
            
            res.push_back(node->val);
            
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        
        return res;
    }
};