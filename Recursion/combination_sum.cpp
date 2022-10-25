#define vvi vector<vector<int>>
#define vi vector<int>

void solve(int i, int k, vi &arr, vi &res, vvi &ans) {
    if(i == arr.size()) {
        if(k == 0)
            ans.push_back(res);
        
        return;
    }
    
    if(k >= arr[i]) {
        res.push_back(arr[i]);
        solve(i,k-arr[i],arr,res,ans);
        res.pop_back();
    }
    
    solve(i+1,k,arr,res,ans);
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vvi ans; vi res;
        solve(0,target,arr,res,ans);
        
        return ans;
    }
};