void setZeroes(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    bool frow = false, fcol = false;

    for(int i = 0; i < n; ++i) 
        if(mat[i][0] == 0) {fcol = true; break;}

    for(int j = 0; j < m; ++j)
        if(mat[0][j] == 0) {frow = true; break;}

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(mat[i][j] == 0) {
                mat[0][j] = 0, mat[i][0] = 0;
            }
        }
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            if(mat[i][0] == 0 or mat[0][j] == 0)
                mat[i][j] = 0;
        }
    }

    if(frow) 
    for(int j = 0; j < m; ++j) mat[0][j] = 0;

    if(fcol)
    for(int i = 0; i < n; ++i) mat[i][0] = 0; 
}