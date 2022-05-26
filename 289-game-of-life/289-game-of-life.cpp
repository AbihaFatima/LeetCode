class Solution {
public:
    //Most Optimised Solution:
    //Time Complexity: O(m*n)
    //Space Complexity: O(1)
    
    int LiveNeighbors(vector<vector<int>>& board,int i,int j, int m, int n){
        int live_neighbors=0;
        
        if(i>0) {
            //upper 
            if(board[i-1][j]==1 || board[i-1][j]==3) live_neighbors++;
        }
        
        if(i<m-1) {
        //lower
        if(board[i+1][j]==1 || board[i+1][j]==3) live_neighbors++;
        }
        
        if(j<n-1) {
            //right
            if(board[i][j+1]==1 || board[i][j+1]==3) live_neighbors++;
        }
        
        if(j>0) {
            //left
            if(board[i][j-1]==1 || board[i][j-1]==3) live_neighbors++;
        }
        
        if(i>0 && j>0) {
            //upper_left
            if(board[i-1][j-1]==1 || board[i-1][j-1]==3) live_neighbors++;
        }
        
        if(i>0 && j<n-1) {
            //upper_right
            if(board[i-1][j+1]==1 || board[i-1][j+1]==3) live_neighbors++;
        }
        
        if(i<m-1 && j>0) {
            //lower_left
            if(board[i+1][j-1]==1 || board[i+1][j-1]==3) live_neighbors++;
        }
        
        if(i<m-1 && j<n-1) {
            //lower_right
            if(board[i+1][j+1]==1 || board[i+1][j+1]==3) live_neighbors++;
        }
        
        return live_neighbors;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int liveN = LiveNeighbors(board,i,j,m,n);
                if(board[i][j]==0)
                {//if dead
                    if(liveN==3){
                        //it lives by if it has exactly 3 live neighbors
                        board[i][j]=2;
                    }
                }
                else if(board[i][j] == 1) {
                    //if alive
                    //==2 || ==3 live
                    if(liveN<2 || liveN>3){
                        //<2 -> under population && >3 -> over population
                        board[i][j]=3; //now this 3 represents newly dead state
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==3) board[i][j]=0;
                if(board[i][j]==2) board[i][j]=1;
            }
        }
        
    }
};