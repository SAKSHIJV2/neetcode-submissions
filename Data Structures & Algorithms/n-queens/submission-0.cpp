class Solution {
public:
    bool isSafe(int row,int col, vector<string>& board){
        int r=row;
        int c=col;
        //same column
        while(r>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
        }
        r=row;
        c=col;
        //left diagonal
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }
        r=row;
        c=col;
        //right diagonal
        while(r>=0 && c<board.size()){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c++;
        }
        return true;
    }
    void solve(int n,vector<vector<string>>& ans,int row,vector<string>& board){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                solve(n,ans,row+1,board);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        int row=0;
        solve(n,ans,row,board);
        return ans;
    }
};
