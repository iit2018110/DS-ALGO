class Solution {
public:
    bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
    }
    
};





// Optimized
#define vb vector<bool>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n,string(n,'.'));
        
        vector<bool> occR(n,false), occLD(2*n-1,false), occUD(2*n-1,false);
        
        solve(0,n,res,ans,occR,occLD,occUD);
        
        return ans;
    }
    
    void solve(int col, int n, vector<string> &res, vector<vector<string>> &ans, vb &occR, vb &occLD, vb &occUD) {
        if(col == n) {
            ans.push_back(res);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(!occR[row] and !occLD[row-col+n-1] and !occUD[row+col]) {
                occR[row] = true;
                occLD[row-col+n-1] = true;
                occUD[row+col] = true;
                
                res[row][col] = 'Q';
                
                solve(col+1,n,res,ans,occR,occLD,occUD);
                
                res[row][col] = '.';
                occR[row] = false;
                occLD[row-col+n-1] = false;
                occUD[row+col] = false;
            }
        }
    }
};