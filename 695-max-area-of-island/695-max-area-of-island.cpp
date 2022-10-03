class Solution {
public:
    int rows,cols;
    void dfs(int i,int j,vector<vector<int>>& grid,int &area){
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]!=1) return;
        
        if(grid[i][j]==1){
            grid[i][j]=2;
            area++;
        }
        dfs(i+1,j,grid,area);
        dfs(i-1,j,grid,area);
        dfs(i,j+1,grid,area);
        dfs(i,j-1,grid,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();
        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int area =0;
                if(grid[i][j] == 1){
                    area=0;
                    dfs(i,j,grid,area);
                }
                ans = max(ans, area);
            }
        }
        return ans;
    }
};