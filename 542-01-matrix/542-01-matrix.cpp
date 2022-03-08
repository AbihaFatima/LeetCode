class Solution {
//Time Complexity : O(m.n)
//Space Complexity : O(m.n) [for maintaining the queue]
public:
    //BFS Approach
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>>q;
        int rows = mat.size();
        int cols = mat[0].size();
        
        //Mark all starting nodes of value 0 in ans matrix as 0
        //as distance from 0 cell is zero
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        //BFS
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            
            //Check for Top row
            if(checkValid(i+1,j,rows,cols) && ans[i+1][j] == -1){
                q.push({i+1,j});
                ans[i+1][j] = ans[i][j] + 1; 
            }
            //Check for Bottom row
            if(checkValid(i-1,j,rows,cols) && ans[i-1][j] == -1){
                q.push({i-1,j});
                ans[i-1][j] = ans[i][j] + 1; 
            }
            //Check for Right
            if(checkValid(i,j+1,rows,cols) && ans[i][j+1] == -1){
                q.push({i,j+1});
                ans[i][j+1] = ans[i][j] + 1; 
            }
            //Check for Left
            if(checkValid(i,j-1,rows,cols) && ans[i][j-1] == -1){
                q.push({i,j-1});
                ans[i][j-1] = ans[i][j] + 1; 
            }
            q.pop();
        }
        return ans;
    }
    
    //Function to check out of bound condition
    bool checkValid(int i, int j, int rows, int cols){
        if(i<0 || i>=rows || j<0 || j>=cols){
            return false;
        }
        return true;
    }
};