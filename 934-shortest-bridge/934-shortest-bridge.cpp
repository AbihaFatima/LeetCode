class Solution {
public:
    //Brute-force approach
    void floodfill(vector<vector<int>>& grid, int i, int j, vector<pair<int,int>> &v){
        //Out of Bound Condition
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        v.push_back({i,j});
        floodfill(grid,i-1,j,v);
        floodfill(grid,i+1,j,v);
        floodfill(grid,i,j-1,v);
        floodfill(grid,i,j+1,v);
        
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int count=0;//count islands
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                    if(count==1){
                        floodfill(grid,i,j,x);
                    }
                    if(count==2){
                        floodfill(grid,i,j,y);
                    }
                }
            }
        }

        //code for finding min dist from one island to another
        //Basically x has vertices of 1st island (vectices of 1's of 1st island)
        //y has vertices of 2nd island (vectices of 1's of 2nd island)
        //so we are calculationg the distance between two vectors of vertices 
        int min_dist = INT_MAX;
        for(int i=0; i<x.size(); i++)
        {
            for(int j=0; j<y.size(); j++)
            {
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }
};