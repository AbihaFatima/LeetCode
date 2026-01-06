class Solution {
public:
    vector<pair<int,int>> dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        int minutes=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty() && fresh > 0){
            //process whatever is in the queue first that is each rotten's oranges level
            int size = q.size();
            minutes++;

            for(int i=0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                //checking and making the neighbours rot
                for(auto d : dir){
                    int newX = x + d.first;
                    int newY = y + d.second;
                    //check if this cell is in bound and is fresh - make it rot
                    if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                        grid[newX][newY] = 2;
                        fresh--;
                        q.push({newX, newY});
                    }
                }
            }
        }
        //if no fresh oranges left return minutes else -1
        return fresh == 0 ? minutes : -1;
    }
};