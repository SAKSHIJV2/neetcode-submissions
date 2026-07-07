class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()){
            return 0;
        }
        if(grid[row][col]==0){
            return 0;
        }
        grid[row][col]=0;
        return 1+dfs(grid,row+1,col)+dfs(grid,row-1,col)+dfs(grid,row,col+1)+dfs(grid,row,col-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==1){
                    int area=dfs(grid,row,col);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
