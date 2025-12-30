class Solution {
public:
    // Direction vector for moving up, down, left, and right
    int dir[4][2] = {
        {-1,0}, 
        {1,0}, 
        {0,-1}, 
        {0,1},
    };
    bool dfsCycle(int x, int y, int parentX, int parentY, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        //mark the current node visted
        visited[x][y]=true;

        //checking its neighbour nodes in 4 directions
        for(int i=0;i<4;i++){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            
            //curr cell should be within bound and should have same value
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == grid[x][y]) {
                
                //if the cell is unvisted and we call dfs on it recursively which returns true so cycle is existing
                if(!visited[newX][newY]){
                    if(dfsCycle(newX, newY, x, y, grid, visited)) //make a dfs call to neighbour cell
                        return true;
                }

                //If the neighbor ie newX and y is not the parent and is already visited, it's a cycle
                else if(visited[newX][newY] && (newX != parentX && newY != parentY))
                    return true;

            }

        }
        return false; //no cycle found
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false)); //2D visited array

        //Start traversing from unvisited cell
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    //start the dfs traversal
                    if(dfsCycle(i, j, -1, -1, grid, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};