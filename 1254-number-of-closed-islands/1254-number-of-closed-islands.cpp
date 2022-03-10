class Solution {
public:
    int rows,cols;
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 ||i>=rows || j<0 || j>=cols || grid[i][j]!=0) return;
        
        //marking 0 as visited
        grid[i][j]=-1;
        
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if((i==0||j==0||i==rows-1||j==cols-1)&&grid[i][j]==0){
                    dfs(i,j,grid);

                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};