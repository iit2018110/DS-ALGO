#define vi vector<int> 


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vi res;
        
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        while(curr!=NULL || !stk.empty()) {
            if(curr != NULL){
                stk.push(curr);
                curr = curr->left;
            } else {
                TreeNode * temp = stk.top()->right;
                if(temp == NULL) {
                    temp = stk.top();
                    stk.pop();
                    res.push_back(temp->val);
                    
                    while(!stk.empty() and stk.top()->right == temp) {
                        temp = stk.top(), stk.pop();
                        res.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        
        return res;
    }
};