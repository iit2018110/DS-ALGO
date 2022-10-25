#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vs vector<string>

int X[] = {1, 0, 0, -1};
int Y[] = {0, -1, 1, 0};
string dir = "DLRU";

void solve(int x, int y, string res, vs &ans, vvb &vis, vvi &mat, int n) {
    if(x == n-1 and y == n-1) {
        ans.push_back(res);
        return;
    }
    
    vis[x][y] = true;
    
    for(int i = 0; i < 4; ++i) {
        int nextX = x + X[i];
        int nextY = y + Y[i];
        
        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && !vis[nextX][nextY] && mat[nextX][nextY]) {
            solve(nextX,nextY,res + dir[i],ans,vis,mat,n);
        }
    }
    
    vis[x][y] = false;
}

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        vector<string> ans;
        vvb vis(n, vector<bool>(n,false));
        if(mat[0][0]) solve(0,0,"",ans,vis,mat,n);
        
        return ans;
    }
};
