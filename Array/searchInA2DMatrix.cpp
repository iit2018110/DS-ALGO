class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        if(n == 0) return false;
        
        int lo = 0;
        int hi = n*m - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);

            int r = mid/matrix[0].size(), c = mid % mat[0].size();

            if(mat[r][c] == target) {
                return true;
            }
            if(mat[r][c] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
