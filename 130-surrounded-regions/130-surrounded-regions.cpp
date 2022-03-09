class Solution {
    //Time Complexity : O(n) for n number of elements in matrix
    //Space Complexity : O(n)
    
    //Intuition:
    //Peform depth first search on all the edge elements of the board to mark all the connected elements with a different flag 
    //(in my case '#' for visisted). Then afterward, mark all the element that are not visisted as 'X' and visisted node back to 'O'.
public:
    int rows,cols;
    void dfs(int i,int j, vector<vector<char>>& b){
        if(i<0 || i>=rows || j<0 || j>=cols || b[i][j]!='O') return;
        b[i][j]='#';
        dfs(i+1,j,b);
        dfs(i-1,j,b);
        dfs(i,j+1,b);
        dfs(i,j-1,b);
    }
    void solve(vector<vector<char>>& b) {
        rows = b.size();
        cols = b[0].size();
        for(int i=0;i<rows;i++){
            dfs(i,0,b);
            dfs(i,cols-1,b);
        }
        for(int j=0;j<cols;j++){
            dfs(0,j,b);
            dfs(rows-1,j,b);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(b[i][j]=='#') 
                    b[i][j]='O';
                else
                    b[i][j]='X';
            }
        }
    }
};