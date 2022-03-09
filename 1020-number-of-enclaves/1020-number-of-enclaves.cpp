class Solution {
public:
    //Time Complexity : O(m.n)
    void dfs(int i,int j,vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]==0) return;
        grid[i][j]=0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        //Calling dfs for all the boundary 1's
        for(int i=0;i<rows;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
        }
        for(int i=0;i<rows;i++){
            if(grid[i][cols-1]==1){
                dfs(i,cols-1,grid);
            }
        }
        for(int j=0;j<cols;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);
            }
        }
        for(int j=0;j<cols;j++){
            if(grid[rows-1][j]==1){
                dfs(rows-1,j,grid);
            }
        }
        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};