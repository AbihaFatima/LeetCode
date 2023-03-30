class Solution {
public:
    //BFS
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int twos=0,ones=0,ans=0;
        //count number of ones and twos
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) ones++;
                else if(grid[i][j]==2){
                    twos++;
                    q.push({i,j});
                }
            }
        }
        if(ones==0) return 0;
        if(twos==0) return -1;
        int count1=twos, count2=0;
        //BFS traversal
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            count1--;
            if(checkValid(i+1,j,rows,cols) && grid[i+1][j]==1){
                ones--;
                q.push({i+1,j});
                grid[i+1][j]=2;
                count2++;
            }
            if(checkValid(i-1,j,rows,cols) && grid[i-1][j]==1){
                ones--;
                q.push({i-1,j});
                grid[i-1][j]=2;
                count2++;
            }
            if(checkValid(i,j+1,rows,cols) && grid[i][j+1]==1){
                ones--;
                q.push({i,j+1});
                grid[i][j+1]=2;
                count2++;
            }
            if(checkValid(i,j-1,rows,cols) && grid[i][j-1]==1){
                ones--;
                q.push({i,j-1});
                grid[i][j-1]=2;
                count2++;
            }
            if(count1 == 0){
                ans++;
                count1=count2;
                count2=0;
            }
        }
        if(ones>0) return -1;
        return ans-1;
    }
    
    bool checkValid(int i, int j, int rows, int cols){
        if(i<0 || j<0 || i>=rows || j>=cols) return false;
        return true;
    }
};