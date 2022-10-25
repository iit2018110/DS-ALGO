vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int> > ans;
    map<int,vector<int>> mp;
    if(root == NULL) return ans;
    
    queue<pair<TreeNode*,int>> q; q.push({root,0});
    while(!q.empty()) {
        pair<TreeNode*,int> p = q.front();
        q.pop();
        TreeNode* u = p.first;
        int x = p.second;
        
        mp[x].push_back(u->val);
        if(u->left) q.push({u->left,x-1});
        if(u->right) q.push({u->right,x+1});
    }
    
    for(auto it = mp.begin(); it!=mp.end(); ++it) {
        ans.push_back(it->second);
    }
    
    return ans;
}