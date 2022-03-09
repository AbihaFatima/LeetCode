class Solution {
private:
    vector<int> x_points = {-1,-1,-1,0,0,1,1,1};
    vector<int> y_points = {-1,0,1,-1,1,-1,0,1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<vector<int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        
        if(grid[0][0]==1 || grid[rows-1][cols-1]==1){
            return -1;
        }
        q.push({0, 0});
        grid[0][0] = 1;
        vector<int>curr;
        while (!q.empty() && !grid[rows-1][cols-1]) {
            curr = q.front();
            q.pop();
            
            for (int i = 0; i < 8; i++) {
                int x = curr[0] + x_points[i];
                int y = curr[1] + y_points[i];
                
                if (checkValid(x, y, rows, cols) && grid[x][y] == 0) {
                    grid[x][y] = grid[curr[0]][curr[1]] + 1;
                    q.push({x, y});
                }
            }
        }
        
        if(grid[rows-1][cols-1]==0){
            return -1;
        }
        
        return grid[rows-1][cols-1];
    }
    
    bool checkValid(int i, int j, int rows,int cols){
        if(i<0 || i>=rows || j<0 || j>=cols){
            return false;
        }
        return true;
    }
};