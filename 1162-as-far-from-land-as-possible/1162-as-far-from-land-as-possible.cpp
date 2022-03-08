class Solution {
    //Time Complexity : O(m.n)
    //Space Complexity : O(m.n)
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int max_dist = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        //Push all the land nodes (having value 1)
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        //BFS
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            //Check Top
            if(checkValid(i+1,j,rows,cols) && grid[i+1][j]==0){
                q.push({i+1,j});
                //Updating the max distance from grid[i][j] to grid[i+1][j]
                grid[i+1][j] = grid[i][j] + 1;
                max_dist = max(max_dist, grid[i+1][j]);
            }
            //Check Bottom
            if(checkValid(i-1,j,rows,cols) && grid[i-1][j]==0){
                q.push({i-1,j});
                grid[i-1][j] = grid[i][j] + 1;
                max_dist = max(max_dist, grid[i-1][j]);
            }
            //Check Left
            if(checkValid(i,j-1,rows,cols) && grid[i][j-1]==0){
                q.push({i,j-1});
                grid[i][j-1] = grid[i][j] + 1;
                max_dist = max(max_dist, grid[i][j-1]);
            }
            //Check Right
            if(checkValid(i,j+1,rows,cols) && grid[i][j+1]==0){
                q.push({i,j+1});
                grid[i][j+1] = grid[i][j] + 1;
                max_dist = max(max_dist, grid[i][j+1]);
            }
            q.pop();
        }
        return (max_dist > 0)? max_dist-1 : -1;
    }
    
    //To Check out of bound condition
    bool checkValid(int i,int j,int rows, int cols){
        if(i<0 || i>=rows || j<0 || j>=cols){
            return false;
        }
        return true;
    }
};