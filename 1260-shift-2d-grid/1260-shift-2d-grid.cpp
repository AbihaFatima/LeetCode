class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> res(rows,vector<int>(cols));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                int newJ=(j+k)%cols; 
                int newI=(i+(j+k)/cols)%rows; 
                res[newI][newJ]=grid[i][j];
                
            }
        }
        return res;
    }
};