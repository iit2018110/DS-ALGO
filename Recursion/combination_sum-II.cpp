#define vvi vector<vector<int>>
#define vi vector<int>

void solve(int idx, int k, vi &arr, vi &res, vvi &ans) {
    if(k == 0) {
        ans.push_back(res);
        return;
    }
    
    for(int i = idx; i < arr.size(); ++i) {
        if(i != idx and arr[i] == arr[i-1]) continue;
        if(k < arr[i]) break;
        res.push_back(arr[i]);
        solve(i+1,k-arr[i],arr,res,ans);
        res.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vvi ans; vi res;
        sort(candidates.begin(),candidates.end());
        
        solve(0,target,candidates,res,ans);
        
        return ans;
    }
};