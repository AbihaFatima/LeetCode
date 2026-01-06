class Solution {
public:
    //Inplace
    vector<pair<int,int>> dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        //we will start from water cells and add heights of neighbouring land cells appending their heights
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //push all water cells into queue and make its height = 0
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    isWater[i][j] = 0;
                }
                else{ //make all land cells as -1 and level by level in bfs we will be appending heights here starting bfs from water cells
                    isWater[i][j] = -1;
                }
            }
        }

        //Start bfs from all water cells
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto d: dir){
                int newX = x+d.first;
                int newY = y+d.second;
                //check if this cell is in bound and the height is undiscovered -> -1
                if(newX >= 0 && newX < m && newY >=0 && newY < n && isWater[newX][newY] == -1){
                    isWater[newX][newY] = isWater[x][y] + 1;
                    q.push({newX,newY});
                }
            }
        }

        return isWater;
    }
};