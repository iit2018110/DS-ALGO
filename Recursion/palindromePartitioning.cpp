class Solution {
public:
    vector<vector<string>> partition(string str) {
        vector<vector<string>> ans;
        vector<string> res;
        
        solve(0,str,res,ans);
        
        return ans;
    }
    
    
    void solve(int idx, string &str, vector<string> &res, vector<vector<string>> &ans) {
        if(idx == str.size()) {
            ans.push_back(res);
            return;
        }
        
        for(int i = idx; i < str.size(); ++i) {
            if(isPelindrome(idx,i,str)) {
                res.push_back(str.substr(idx,i-idx+1));
                solve(i+1,str,res,ans);
                res.pop_back();
            }
        }
    }
    
    bool isPelindrome(int s, int e, string str) {
        while(s <= e) {
            if(str[s++] != str[e--])
                return false;
        }
        
        return true;
    }
};