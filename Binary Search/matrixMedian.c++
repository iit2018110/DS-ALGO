#define vvi vector<vector<int>>

int solve(vvi &mat, int k) {
    int ans = 0;
    
    for(int i = 0; i < mat.size(); ++i) {
        int lo = 0, hi = mat[0].size()-1;
        int res = 0;
        while(lo <= hi) {
            int m = lo + (hi - lo)/2;
            if(mat[i][m] > k) hi = m-1;
            else {
                res = max(res,m+1);
                lo = m+1;
            }
        }
        
        ans += res;
    }
    
    return ans;
    
}

int Solution::findMedian(vector<vector<int> > &mat) {
    int n = mat.size(), m = mat[0].size();
    int l = 1, h = INT_MAX, res = INT_MAX;
    while(l <= h) {
        int mid = l + (h-l)/2;
        int temp = solve(mat,mid);

        if(temp <= (m*n)/2) l = mid+1;
        else {
            res = min(res,mid);
            h = mid-1;
        }
    }
    
    return res;
}
