vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vvi ans;
    if(root == NULL) return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    bool l2r = true;
    
    while(!q.empty()) {
        int sz = q.size();
        vi res(sz);
        
        for(int i = 0; i < sz; ++i) {
            TreeNode *node = q.front();
            q.pop();
            
            if(l2r) res[i] = node->val;
            else res[sz-1-i] = node->val;
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        ans.push_back(res);
        l2r = !l2r;
    }
    
    return ans;
}