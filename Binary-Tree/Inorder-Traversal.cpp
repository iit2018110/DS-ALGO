#define vi vector<int> 


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vi res;
        if(root==NULL) return res;
        
        TreeNode * curr = root;
        stack<TreeNode*> stk;
        while(true) {
            if(curr != NULL) {
                stk.push(curr);
                curr = curr->left;
            } else {
                if(stk.empty()) break;
                curr = stk.top();
                stk.pop();
                
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return res;
    }
};