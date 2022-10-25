bool check(int v, int c, int * col, bool graph[101][101], int n) {
    for(int i = 0; i < n; ++i) {
        if(i != v and graph[v][i] and col[i] == c)
            return false;
    }
    
    return true;
}

bool solve(int v,int * col, bool graph[101][101], int m, int n) {
    if(v == n) return true;
    
    for(int c = 0; c < m; ++c) {
        if(check(v,c,col,graph,n)) {
            col[v] = c;
            if(solve(v+1,col,graph,m,n)) return true;
            
            col[v] = -1;
        }
    }
    
    return false;
}


bool graphColoring(bool graph[101][101], int m, int n)
{
    int col[n]; memset(col,-1,sizeof(col));
    return solve(0,col,graph,m,n);
}