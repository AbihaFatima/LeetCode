class Solution {
public:
    //TC: O(m.n)
    int rows,cols;
    void dfs(int i,int j,vector<vector<char>>& grid){
         // boundary checking
        if(i<0 || j<0 || i>=rows || j>=cols){
            return;
        }
        // return if current position is of water or is already visited
        else if(grid[i][j]=='0' || grid[i][j]=='#') return;
        
         // mark the current as visited
        grid[i][j] = '#';
        
        // do DFS in all 4 directions
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int island=0;
        // We make each 1 as # in when it is visited
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // do DFS in case has not been visited and there is land
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    island++;
                }
            }
        }
        return island;
    }
};