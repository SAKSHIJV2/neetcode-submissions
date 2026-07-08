class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int minutes=0;
        int fresh=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==2){
                    q.push({row,col});
                }
                if(grid[row][col]==1){
                    fresh++;
                }
            }
        }
        vector<pair<int,int>> dir={
            {-1,0},
            {+1,0},
            {0,+1},
            {0,-1}
        };
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                int r=curr.first;
                int c=curr.second;
                for(auto it:dir){
                    int newr=r+it.first;
                    int newc=c+it.second;
                    if(newr<0 || newr>=rows || newc<0 || newc>=cols){
                        continue;
                    }
                    if(grid[newr][newc]==0){
                        continue;
                    }
                    if(grid[newr][newc]!=1){
                        continue;
                    }
                    grid[newr][newc]=2;
                    fresh--;
                    q.push({newr,newc});
                }
                
            }
            if(!q.empty()){
                minutes++;
            }
        }
        if(fresh>0){
            return -1;
        }
        return minutes;
    }
};
