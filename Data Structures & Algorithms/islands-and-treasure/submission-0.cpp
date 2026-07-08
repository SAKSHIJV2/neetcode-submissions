class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<pair<int,int>> directions={
            {-1,0},
            {+1,0},
            {0,+1},
            {0,-1}
        };
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==0){
                    q.push({row,col});
                }
            }
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int r=curr.first;
            int c=curr.second;
            for(auto it:directions){
                int newr=r+it.first;
                int newc=c+it.second;
                if(newr<0 || newr>=rows || newc<0 || newc>=cols){
                    continue;
                }
                if(grid[newr][newc]!=INT_MAX){
                    continue;
                }
                grid[newr][newc]=grid[r][c]+1;
                q.push({newr,newc});
            }
        }
    }
};
