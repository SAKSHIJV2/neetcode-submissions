class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int index,int row,int col
    ,vector<vector<bool>>& visited){
        if(index==word.size()){
            return true;
        }
        if(row<0 || row>=board.size()  || col<0 || col>=board[0].size()){
            return false;
        }
        if(visited[row][col]){
            return false;
        }
        if(board[row][col]!=word[index]){
            return false;
        }
        visited[row][col]=true;
        bool found=
        dfs(board,word,index+1,row+1,col,visited) ||
        dfs(board,word,index+1,row-1,col,visited) ||
        dfs(board,word,index+1,row,col+1,visited) ||
        dfs(board,word,index+1,row,col-1,visited) ;

        visited[row][col]=false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        string curr;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,0,i,j,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
